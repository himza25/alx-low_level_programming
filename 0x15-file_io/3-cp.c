#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point.
 * @argc: argument count
 * @argv: arguments passed
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	error_checks(argc, argv[1], argv[2]);
	copy_file(argv[1], argv[2]);
	return (0);
}

/**
 * error_checks - check for errors
 * @arg_count: number of arguments
 * @file_from: source file
 * @file_to: destination file
 */
void error_checks(int arg_count, char *file_from, char *file_to)
{
	(void)arg_count;
	if (access(file_from, R_OK) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	if (open(file_to, O_CREAT) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
}

/**
 * copy_file - copy contents from one file to another
 * @file_from: source file
 * @file_to: destination file
 */
void copy_file(char *file_from, char *file_to)
{
	int fd_from, fd_to, read_val, write_val;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd_from == -1 || fd_to == -1)
		exit(-1);

	while ((read_val = read(fd_from, buffer, 1024)) > 0)
	{
		write_val = write(fd_to, buffer, read_val);
		if (write_val != read_val)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}
	if (read_val == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}
