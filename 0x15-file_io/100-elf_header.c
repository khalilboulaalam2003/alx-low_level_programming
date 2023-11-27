#include "main.h"

/**
 * display_error - Displays an error message to stderr and exits with a status code.
 * @message: The error message to display.
 * @status: The exit status code.
 */
void display_error(const char *message, int status) {
    dprintf(2, "%s\n", message);
    exit(status);
}

/**
 * display_elf_header - Displays ELF header information.
 * @header: Pointer to the ELF header.
 */
void display_elf_header(unsigned char *header) {
    printf("ELF Header:\n");
    printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
           header[0], header[1], header[2], header[3], header[4], header[5], header[6], header[7],
           header[8], header[9], header[10], header[11], header[12], header[13], header[14], header[15]);
    printf("  Class:                             ELF%d\n", header[4] == 1 ? 32 : (header[4] == 2 ? 64 : -1));
    printf("  Data:                              2's complement, %s endian\n", header[5] == 1 ? "little" : "big");
    printf("  Version:                           %d (current)\n", header[6]);
    printf("  OS/ABI:                            %d\n", header[7]);
    printf("  ABI Version:                       %d\n", header[8]);
    printf("  Type:                              %d\n", *(unsigned short *)&header[16]);
    printf("  Entry point address:               0x%x\n", *(unsigned int *)&header[24]);
}

/**
 * main - Entry point for the program.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, or the exit status code on failure.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_error("Usage: elf_header elf_filename", 98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        display_error("Error opening file", 98);
    }

    unsigned char elf_header[ELF_HEADER_SIZE];
    ssize_t bytes_read = read(fd, elf_header, ELF_HEADER_SIZE);
    if (bytes_read == -1 || bytes_read != ELF_HEADER_SIZE) {
        close(fd);
        display_error("Error reading ELF header", 98);
    }

    display_elf_header(elf_header);

    if (close(fd) == -1) {
        display_error("Error closing file descriptor", 98);
    }

    return 0;
}

