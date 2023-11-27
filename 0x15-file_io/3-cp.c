#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

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
 * main - Entry point for the program.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, or the exit status code on failure.
 */
int main(int argc, char *argv[]) {
    int fd_from, fd_to, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        display_error("Usage: cp file_from file_to", 97);
    }

    fd_from = open(argv[1], O_RDONLY);

    if (fd_from == -1) {
        display_error("Error: Can't read from file", 98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd_to == -1) {
        close(fd_from);
        display_error("Error: Can't write to file", 99);
    }

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);

        if (bytes_written != bytes_read) {
            close(fd_from);
            close(fd_to);
            display_error("Error: Can't write to file", 99);
        }
    }

    if (bytes_read == -1) {
        close(fd_from);
        close(fd_to);
        display_error("Error: Can't read from file", 98);
    }

    if (close(fd_from) == -1 || close(fd_to) == -1) {
        display_error("Error: Can't close file descriptor", 100);
    }

    return 0;
}


