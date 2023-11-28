#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

/**
 * create_empty_file - Just create a file with set permissions and a filename.
 * @filename: The filename.
 */
void create_empty_file(const char *filename)
{
    int file;

    file = open(filename, O_CREAT);
    close(file);
}

/**
 * create_file - Write content to a file, if it exists.
 *               If not, the function will create it and write to it.
 * @filename: The file name.
 * @text_content: The content that the function will write to the file.
 * 
 * Return: 0 if OK, -1 if an error occurred.
 */
int create_file(const char *filename, char *text_content)
{
    int file;
    int flag; /* 0 if the file exists, 1 if the file has been created */
    int trunc_code;
    int write_code;
    unsigned int len;
    mode_t FILE_PERMISSIONS;

    FILE_PERMISSIONS = S_IRUSR | S_IWUSR;

    if (text_content == NULL)
        create_empty_file(filename);

    len = strlen(text_content);

    if (filename == NULL)
        return (-1);

    file = open(filename, O_RDWR); /* File already exists */
    flag = 0;

    if (file == -1)
    {
        file = open(filename, O_CREAT | O_RDWR, FILE_PERMISSIONS); /* File does not exist */
        flag = 1;

        if (file == -1)
            return (-1);
    }

    if (flag == 0) /* File exists */
    {
        trunc_code = ftruncate(file, len);
        if (trunc_code != 0)
            return (-1);

        write_code = write(file, text_content, len);
        if (write_code == -1)
            return (-1);
    }
    else if (flag == 1) /* File does not exist */
    {
        write_code = write(file, text_content, len);
        if (write_code == -1)
            return (-1);
    }

    close(file);
    return (0);
}

