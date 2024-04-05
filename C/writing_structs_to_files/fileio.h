#ifndef FILEIO_H
#define FILEIO_H

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int get_file_length(FILE* file);
FILE* open_file(const char* file_name, const char* mode);
unsigned char* read_file(FILE* file, int file_size);
int write_file(FILE* file, unsigned char* data, int file_size);

#endif