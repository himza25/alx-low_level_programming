#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * verifyElfSignature - Check the ELF file signature
 * @signature: Pointer to header signature
 */
void verifyElfSignature(unsigned char *signature)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (signature[i] != 127 &&
		    signature[i] != 'E' &&
		    signature[i] != 'L' &&
		    signature[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * displayMagicNumbers - Display the magic numbers
 * @signature: Pointer to header signature
 */
void displayMagicNumbers(unsigned char *signature)
{
	int i;

	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", signature[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * displayClass - Display the ELF class
 * @signature: Pointer to header signature
 */
void displayClass(unsigned char *signature)
{
	printf(" Class: ");
	switch (signature[EI_CLASS])
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
		printf("<unknown: %x>\n", signature[EI_CLASS]);
	}
}

/* ... [Rest of the functions remain similar with descriptions] ... */

/**
 * main - Main entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fileDescriptor, bytesRead;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <filename>\n", argv[0]);
		exit(98);
	}

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (!header)
	{
		close(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(98);
	}

	bytesRead = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
	if (bytesRead == -1)
	{
		free(header);
		close(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: Failed to read file\n", argv[1]);
		exit(98);
	}

	verifyElfSignature(header->e_ident);
	printf("ELF Header:\n");
	displayMagicNumbers(header->e_ident);
	displayClass(header->e_ident);
	free(header);
	close(fileDescriptor);
	return (0);
}
