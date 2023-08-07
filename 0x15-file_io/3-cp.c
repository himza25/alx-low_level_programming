#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file
 * @argc: Argument count
 * @argv: Array of arguments
 *
 * Return: 0 on success, or one of the error codes on failure
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t read_bytes, write_bytes;
	char buf[BUFFER_SIZE];

	if (argc != 3)
		error_exit(97, NULL, 0);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_exit(98, argv[1], 0);

	file_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (file_to == -1)
		error_exit(99, argv[2], file_from);

	while ((read_bytes = read(file_from, buf, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(file_to, buf, read_bytes);
		if (write_bytes != read_bytes)
			error_exit(99, argv[2], file_from);
	}

	if (read_bytes == -1)
		error_exit(98, argv[1], file_from);

	if (close(file_from) == -1)
		error_exit(100, NULL, file_from);

	if (close(file_to) == -1)
		error_exit(100, NULL, file_to);

	return (0);
}

/**
 * error_exit - handle errors and exit program
 * @code: error code
 * @filename: filename causing error
 * @fd: file descriptor to close
 */
void error_exit(int code, char *filename, int fd)
{
	if (fd > 0)
		close(fd);

	switch (code)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		break;
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		break;
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		break;
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		break;
	}
	exit(code);
}
