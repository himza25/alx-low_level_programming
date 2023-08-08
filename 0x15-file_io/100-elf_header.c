#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validate_elf_format(unsigned char *identifiers);
void display_magic_numbers(unsigned char *identifiers);
void display_class_info(unsigned char *identifiers);
void display_data_info(unsigned char *identifiers);
void display_version_info(unsigned char *identifiers);
void display_osabi_info(unsigned char *identifiers);
void display_abi_version_info(unsigned char *identifiers);
void display_type_info(unsigned int type_info, unsigned char *identifiers);
void display_entry_point_info(unsigned long int entry_point,
		unsigned char *identifiers);
void close_elf_file(int file_descriptor);

/**
 * validate_elf_format - Checks if the provided file is in ELF format.
 * @identifiers: Pointer to the array with ELF magic numbers.
 * Description: If the file is not ELF, exit with code 98.
 */
void validate_elf_format(unsigned char *identifiers)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (identifiers[i] != 127 &&
		    identifiers[i] != 'E' &&
		    identifiers[i] != 'L' &&
		    identifiers[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * display_magic_numbers - Display the magic numbers of the ELF header.
 * @identifiers: Pointer to the array with ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */
void display_magic_numbers(unsigned char *identifiers)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", identifiers[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * display_class_info - Shows the class of the ELF header.
 * @identifiers: Pointer to array with ELF class info.
 */
void display_class_info(unsigned char *identifiers)
{
	printf("  Class:                             ");
	switch (identifiers[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", identifiers[EI_CLASS]);
	}
}

/**
 * display_data_info - Shows the data of the ELF header.
 * @identifiers: Pointer to array with ELF data info.
 */
void display_data_info(unsigned char *identifiers)
{
	printf("  Data:                              ");
	switch (identifiers[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", identifiers[EI_CLASS]);
	}
}

/**
 * display_version_info - Shows the version of the ELF header.
 * @identifiers: Pointer to array with ELF version info.
 */
void display_version_info(unsigned char *identifiers)
{
	printf("  Version:                           %d",
	       identifiers[EI_VERSION]);
	switch (identifiers[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * display_osabi_info - Shows the OS/ABI of the ELF header.
 * @identifiers: Pointer to array with ELF OS/ABI info.
 */
void display_osabi_info(unsigned char *identifiers)
{
	printf("  OS/ABI:                            ");
	switch (identifiers[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", identifiers[EI_OSABI]);
	}
}

/**
 * display_abi_version_info - Shows the ABI version of the ELF header.
 * @identifiers: Pointer to array with ELF ABI version info.
 */
void display_abi_version_info(unsigned char *identifiers)
{
	printf("  ABI Version:                       %d\n",
	       identifiers[EI_ABIVERSION]);
}

/**
 * display_type_info - Shows the type of the ELF header.
 * @type_info: ELF type.
 * @identifiers: Pointer to array with ELF class info.
 */
void display_type_info(unsigned int type_info, unsigned char *identifiers)
{
	if (identifiers[EI_DATA] == ELFDATA2MSB)
		type_info >>= 8;
	printf("  Type:                              ");
	switch (type_info)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type_info);
	}
}

/**
 * display_entry_point_info - Shows the entry point of the ELF header.
 * @entry_point: Address of the ELF entry point.
 * @identifiers: Pointer to array with ELF class info.
 */
void display_entry_point_info(unsigned long int entry_point,
		unsigned char *identifiers)
{
	printf("  Entry point address:               ");
	if (identifiers[EI_DATA] == ELFDATA2MSB)
	{
		entry_point = ((entry_point << 8) & 0xFF00FF00) |
			  ((entry_point >> 8) & 0xFF00FF);
		entry_point = (entry_point << 16) | (entry_point >> 16);
	}
	if (identifiers[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry_point);
	else
		printf("%#lx\n", entry_point);
}

/**
 * close_elf_file - Closes the specified ELF file.
 * @file_descriptor: File descriptor of the ELF file.
 * Description: Exit with code 98 if the file can't be closed.
 */
void close_elf_file(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", file_descriptor);
		exit(98);
	}
}

/**
 * main - Display information from the ELF header of the specified file.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, exit with code 98 on failure.
 * Description: Exit with code 98 if not an ELF file or function failure.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *elf_header;
	int open_fd, read_fd;

	open_fd = open(argv[1], O_RDONLY);
	if (open_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		close_elf_file(open_fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_fd = read(open_fd, elf_header, sizeof(Elf64_Ehdr));
	if (read_fd == -1)
	{
		free(elf_header);
		close_elf_file(open_fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	validate_elf_format(elf_header->e_ident);
	printf("ELF Header:\n");
	display_magic_numbers(elf_header->e_ident);
	display_class_info(elf_header->e_ident);
	display_data_info(elf_header->e_ident);
	display_version_info(elf_header->e_ident);
	display_osabi_info(elf_header->e_ident);
	display_abi_version_info(elf_header->e_ident);
	display_type_info(elf_header->e_type, elf_header->e_ident);
	display_entry_point_info(elf_header->e_entry, elf_header->e_ident);

	free(elf_header);
	close_elf_file(open_fd);
	return (0);
}

