#include "main.h"

#define BUF_SIZE 1024

int open_files(char *file_from, char *file_to);
void close_files(int from_fd, int to_fd);
void copy_files(int from_fd, int to_fd, char *file_from, char *file_to);

/**
 * main - main function
 * @argc: Number of arguments.
 * @argv: Argument vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fd = open_files(argv[1], argv[2]);
	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	copy_files(from_fd, to_fd, argv[1], argv[2]);
	close_files(from_fd, to_fd);
	return (0);
}

/**
 * open_files - Opens the source file for reading.
 * @file_from: The source file.
 * @file_to: The destination file.
 * Return: File descriptor of the source file.
 */
int open_files(char *file_from, char *file_to)
{
	int fd;

	fd = open(file_from, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	return (fd);
}

/**
 * close_files - Closes file descriptors.
 * @from_fd: File descriptor of the source file.
 * @to_fd: File descriptor of the destination file.
 */
void close_files(int from_fd, int to_fd)
{
	if (close(from_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
		exit(100);
	}
	if (close(to_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
		exit(100);
	}
}

/**
 * copy_files - Copies content from one file to another.
 * @from_fd: File descriptor of the source file.
 * @to_fd: File descriptor of the destination file.
 * @file_from: The source file.
 * @file_to: The destination file.
 */
void copy_files(int from_fd, int to_fd, char *file_from, char *file_to)
{
	int r, w;
	char buf[BUF_SIZE];

	while ((r = read(from_fd, buf, BUF_SIZE)) > 0)
	{
		w = write(to_fd, buf, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(from_fd);
			close(to_fd);
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(from_fd);
		exit(98);
	}
}
