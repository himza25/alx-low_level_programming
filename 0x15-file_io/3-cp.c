#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char *initialize_buffer(void);
void safe_close(int fd);

/**
 * initialize_buffer - Allocates space for a buffer.
 *
 * Return: A pointer to the buffer.
 */
char *initialize_buffer(void)
{
	char *buffer;

	buffer = malloc(BUFFER_SIZE);

	if (!buffer)
	{
		dprintf(STDERR_FILENO, "Error: Buffer initialization failed\n");
		exit(99);
	}

	return (buffer);
}

/**
 * safe_close - Safely closes a file descriptor and checks for errors.
 * @fd: File descriptor.
 */
void safe_close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Main function to copy contents from one file to another.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, error code on failure.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd;
	ssize_t read_bytes, written_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = initialize_buffer();

	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		safe_close(from_fd);
		exit(99);
	}

	while ((read_bytes = read(from_fd, buffer, BUFFER_SIZE)) > 0)
	{
		written_bytes = write(to_fd, buffer, read_bytes);
		if (written_bytes != read_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			safe_close(from_fd);
			safe_close(to_fd);
			exit(99);
		}
	}

	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		safe_close(from_fd);
		safe_close(to_fd);
		exit(98);
	}

	free(buffer);
	safe_close(from_fd);
	safe_close(to_fd);

	return (0);
}
