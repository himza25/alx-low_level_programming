#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * verify_elf - Verifies if file is ELF.
 * @id: ELF identifier.
 */
void verify_elf(unsigned char *id)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (id[i] != 127 && id[i] != 'E' && id[i] != 'L' && id[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * show_magic - Displays the magic number.
 * @id: ELF identifier.
 */
void show_magic(unsigned char *id)
{
	int i;

	printf("  Magic:\t");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", id[i]);
	}
	printf("\n");
}

/**
 * show_class - Displays the class.
 * @id: ELF identifier.
 */
void show_class(unsigned char *id)
{
	printf("  Class:\t");
	switch (id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("None\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("Unknown: %x\n", id[EI_CLASS]);
	}
}

/**
 * show_data - Displays the data format.
 * @id: ELF identifier.
 */
void show_data(unsigned char *id)
{
	printf("  Data:\t\t");
	switch (id[EI_DATA])
	{
	case ELFDATANONE:
		printf("None\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Unknown: %x\n", id[EI_DATA]);
	}
}

/**
 * show_version - Displays the ELF version.
 * @id: ELF identifier.
 */
void show_version(unsigned char *id)
{
	printf("  Version:\t");
	switch (id[EI_VERSION])
	{
	case EV_NONE:
		printf("Invalid version\n");
		break;
	case EV_CURRENT:
		printf("Current version\n");
		break;
	default:
		printf("Unknown: %x\n", id[EI_VERSION]);
	}
}

/**
 * show_osabi - Displays the OS ABI.
 * @id: ELF identifier.
 */
void show_osabi(unsigned char *id)
{
	printf("  OS/ABI:\t");
	switch (id[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX System V ABI\n");
		break;
	/* ... add other known types ... */
	default:
		printf("Unknown: %x\n", id[EI_OSABI]);
	}
}

/**
 * show_abiversion - Displays the ABI version.
 * @id: ELF identifier.
 */
void show_abiversion(unsigned char *id)
{
	printf("  ABI Version:\t%d\n", id[EI_ABIVERSION]);
}

/**
 * show_type - Displays the ELF type.
 * @type: ELF type.
 */
void show_type(Elf64_Half type)
{
	printf("  Type:\t\t");
	switch (type)
	{
	case ET_NONE:
		printf("No file type\n");
		break;
	case ET_REL:
		printf("Relocatable file\n");
		break;
	case ET_EXEC:
		printf("Executable file\n");
		break;
	case ET_DYN:
		printf("Shared object file\n");
		break;
	case ET_CORE:
		printf("Core file\n");
		break;
	default:
		printf("Unknown: %x\n", type);
	}
}

/**
 * close_file - Closes file.
 * @fd: File descriptor.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * read_elf_header - Reads the ELF header.
 * @fd: File descriptor.
 * @hdr: Pointer to header.
 * Return: 0 on success, or 1 on error.
 */
int read_elf_header(int fd, Elf64_Ehdr *hdr)
{
	int ret = read(fd, hdr, sizeof(Elf64_Ehdr));
	if (ret != sizeof(Elf64_Ehdr))
	{
		free(hdr);
		close_file(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file\n");
		return (1);
	}
	return (0);
}

/**
 * print_elf_header - Prints the ELF header.
 * @hdr: Pointer to header.
 */
void print_elf_header(Elf64_Ehdr *hdr)
{
	verify_elf(hdr->e_ident);
	printf("ELF Header Information:\n");
	show_magic(hdr->e_ident);
	show_class(hdr->e_ident);
	show_data(hdr->e_ident);
	show_version(hdr->e_ident);
	show_osabi(hdr->e_ident);
	show_abiversion(hdr->e_ident);
	show_type(hdr->e_type);
}

/**
 * main - Main function.
 * @argc: Arguments count.
 * @argv: Arguments vector.
 * Return: 0 on success, or 98 on error.
 */
int main(int argc, char **argv)
{
	Elf64_Ehdr *hdr;
	int fd;

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

	hdr = malloc(sizeof(Elf64_Ehdr));
	if (!hdr)
	{
		close_file(fd);
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(98);
	}

	if (read_elf_header(fd, hdr))
		exit(98);

	print_elf_header(hdr);

	free(hdr);
	close_file(fd);
	return (0);
}
