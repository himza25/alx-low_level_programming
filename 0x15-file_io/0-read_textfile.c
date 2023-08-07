#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: Name of the file to be read.
 * @letters: Number of letters to read and print.
 * Return: The actual number of letters it could read and print, 0 if fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_length, written_length;
	char *buffer;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(fd);
		return (0);
	}

	read_length = read(fd, buffer, letters);
	close(fd);

	if (read_length == -1)
	{
		free(buffer);
		return (0);
	}

	written_length = write(STDOUT_FILENO, buffer, read_length);
	free(buffer);

	if (written_length == -1 || read_length != written_length)
		return (0);

	return (written_length);
}
