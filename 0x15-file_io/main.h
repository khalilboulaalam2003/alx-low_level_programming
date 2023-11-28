#ifndef _IO_H
#define _IO_H

#include <unistd.h>

/**
 * `read_textfile` - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters);

/**
 * `create_file` - Creates a file with a given text content.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content);

/**
 * `append_text_to_file` - Appends text to the end of a file.
 * @filename: The name of the file to append to.
 * @text_content: The content to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content);

/**
 * struct BUFFER - Simple buffer handling structure.
 * @size: The size of the string.
 * @string: A string.
 */
typedef struct BUFFER
{
	int size;
	char *string;
} buffer;

#endif /* _IO_H */

