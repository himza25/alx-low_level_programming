#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_magic - prints the magic bytes of the ELF header
 * @e_ident: the ELF file identity header
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * print_class - prints the architecture of the ELF file (32/64 bits)
 * @e_class: the ELF class byte
 */
void print_class(unsigned char e_class)
{
	printf("  Class:                             ");
	if (e_class == ELFCLASS32)
	{
		printf("ELF32\n");
	}
	else if (e_class == ELFCLASS64)
	{
		printf("ELF64\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_class);
	}
}

/**
 * print_data - prints the data format of the ELF file (little/big endian)
 * @e_data: the ELF data byte
 */
void print_data(unsigned char e_data)
{
	printf("  Data:                              ");
	if (e_data == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
	}
	else if (e_data == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_data);
	}
}

/**
 * print_version - prints the version of the ELF file
 * @e_version: the ELF version
 */
void print_version(unsigned char e_version)
{
	printf("  Version:                           %d ", e_version);
	if (e_version == EV_CURRENT)
	{
		printf("(current)\n");
	}
	else
	{
		printf("\n");
	}
}

/**
 * print_osabi - prints the OS/ABI of the ELF file
 * @e_osabi: the ELF OS/ABI byte
 */
void print_osabi(unsigned char e_osabi)
{
	printf("  OS/ABI:                            ");
	switch (e_osabi)
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %x>\n", e_osabi);
	}
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}

	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
	{
		perror("Error reading file");
		close(fd);
		exit(1);
	}

	if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Not an ELF file\n");
		close(fd);
		exit(1);
	}

	print_magic(ehdr.e_ident);
	print_class(ehdr.e_ident[EI_CLASS]);
	print_data(ehdr.e_ident[EI_DATA]);
	print_version(ehdr.e_ident[EI_VERSION]);
	print_osabi(ehdr.e_ident[EI_OSABI]);

	close(fd);
	return (0);
}
