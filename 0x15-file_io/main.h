#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/* Function declarations */

/* 0-read_textfile.c */
ssize_t read_textfile(const char *filename, size_t letters);

/* 1-create_file.c */
int create_file(const char *filename, char *text_content);

/* 2-append_text_to_file.c */
int append_text_to_file(const char *filename, char *text_content);

/* 3-cp.c */
void print_error_exit(const char *msg);
void copy_file(const char *src_filename, const char *dest_filename);

/* 100-elf_header.c */
void print_elf_header(const Elf64_Ehdr *header);

#endif /* MAIN_H */

