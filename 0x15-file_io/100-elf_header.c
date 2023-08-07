#include "main.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Array of arguments
 *
 * Return: EXIT_SUCCESS on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	/* Read the initial bytes of the file into e_ident for verification */
	if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	/* Verify this is an ELF file */
	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
		e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "%s is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}

	/* More code to handle extracting and printing ELF header details */

	close(fd);
	return (EXIT_SUCCESS);
}
