#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

/**
 * append_text_to_file - Appends content to a file.
 * @filename: The name of the file.
 * @text_content: The content to be appended to the file.
 *
 * Return: 1 on success, -1 if an error occurred.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int file;
    int write_code;

    if (filename == NULL)
        return (-1);

    file = open(filename, O_APPEND | O_WRONLY);
    if (file == -1)
        return (-1);

    if (text_content != NULL)
        write_code = write(file, text_content, strlen(text_content));

    if (write_code == -1)
        return (-1);

    return (1);
}

