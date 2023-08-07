#include "main.h"

/**
 * create_file - Creates a file with specified content.
 * @filename: Name of the file to be created.
 * @text_content: Content to be written into the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, write_length, i;

	if (!filename)
		return (-1);

	/* Open for writing. If file doesn't exist, create it with 0600 permissions.
	   If it exists, truncate it. */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	// If there's no content to write, just close the file and return.
	if (!text_content)
	{
		close(fd);
		return (1);
	}

	// Get the length of text_content.
	for (i = 0; text_content[i]; i++)
		;

	write_length = write(fd, text_content, i);
	close(fd);

	if (write_length == -1)
		return (-1);

	return (1);
}
