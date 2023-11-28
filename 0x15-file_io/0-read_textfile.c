#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - Reads from a file and outputs to standard output.
 * @filename: The file name.
 * @letters: Number of bytes the function is allowed to write to STDOUT.
 * 
 * Return: The count of all characters in the file.
 */
ssize_t read_textfile(const char *filename, ssize_t letters)
{
    int fp;
    ssize_t write_count, read_count;
    char *BUFFER;

    if (filename == NULL || letters == 0)  // Check if the file doesn't exist or letters is 0.
        return (0);

    // Open the file.
    fp = open(filename, O_RDONLY);
    if (fp == -1)
        return (0);

    // Handle allocation.
    BUFFER = malloc(sizeof(char) * letters);
    if (BUFFER == NULL)
    {
        free(BUFFER);
        return (0);
    }

    // Read bytes of size letters from the file.
    read_count = read(fp, BUFFER, letters);
    if (read_count == -1)
    {
        free(BUFFER);
        return (0);
    }

    // Write the bytes of size letters to STDOUT.
    write_count = write(1, BUFFER, read_count);
    if (write_count == -1 || write_count != read_count)
    {
        free(BUFFER);
        return (0);
    }

    free(BUFFER);
    close(fp);
    return (write_count);
}

