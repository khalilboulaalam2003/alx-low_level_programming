#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - Reads from a file and outputs to standard output.
 * @filename: The file name.
 * @letters: The number of bytes the function is allowed to write to STDOUT.
 * Return: The count of all characters in the file.
 */
ssize_t read_textfile(const char *filename, ssize_t letters)
{
    int file_descriptor;
    ssize_t write_count, read_count;
    char *buffer;

    if (filename == NULL || letters == 0) /* File doesn't exist or invalid letters */
        return (0);

    /* Open the file */
    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
    {
        return (0);
    }

    /* Allocate memory for the buffer */
    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
    {
        close(file_descriptor);
        return (0);
    }

    /* Read bytes of size letters from the file */
    read_count = read(file_descriptor, buffer, letters);
    if (read_count == -1)
    {
        free(buffer);
        close(file_descriptor);
        return (0);
    }

    /* Write the bytes of size letters to STDOUT */
    write_count = write(1, buffer, read_count);
    if (write_count == -1 || (write_count != read_count))
    {
        free(buffer);
        close(file_descriptor);
        return (0);
    }

    /* Clean up and close the file */
    free(buffer);
    close(file_descriptor);

    return (write_count);
}
