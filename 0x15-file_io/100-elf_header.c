#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Entry point, opens file and reads the ELF header.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	int fd;
	char magic[16];

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (read(fd, magic, 16) != 16 || magic[0] != 0x7f || magic[1] != 'E' ||
	    magic[2] != 'L' || magic[3] != 'F')
	{
		dprintf(STDERR_FILENO, "%s is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");

	close(fd);
	return (0);
}
