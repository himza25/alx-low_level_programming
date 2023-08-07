#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * validate_elf - validates ELF
 * @e_ident: Identifier for ELF
 */
void validate_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 0x7f ||
		e_ident[1] != 'E' ||
		e_ident[2] != 'L' ||
		e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * display_elf_header_info - displays the ELF header info
 * @header: The ELF header
 */
void display_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:\t");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("  Class:\tInvalid class\n");
			break;
		case ELFCLASS32:
			printf("  Class:\tELF32\n");
			break;
		case ELFCLASS64:
			printf("  Class:\tELF64\n");
			break;
		default:
			printf("  Class:\tUnknown\n");
			break;
	}

	/* ... rest of the function remains the same, with similar corrections ... */
}

/**
 * main - Main function
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr *header;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	if (read(fd, header, sizeof(Elf64_Ehdr)) == -1)
	{
		free(header);
		close(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	validate_elf(header->e_ident);
	printf("ELF Header:\n");
	display_elf_header_info(header);

	free(header);
	close(fd);
	return (0);
}
