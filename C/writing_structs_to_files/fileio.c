#include "fileio.h"

int get_file_length(FILE* file)
{
    int size = 0;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    return size;
}

FILE* open_file(const char* file_name, const char* mode)
{
    FILE* file = fopen(file_name, mode);

    if(!file)
    {
        printf("[Error]: File failed to open.\n");
        return NULL;
    }

    return file;
}

unsigned char* read_file(FILE* file, int file_size)
{
    unsigned char* buffer = (unsigned char*)malloc(file_size * sizeof(unsigned char) + 1);

    if(buffer == NULL)
    {
        printf("[Error]: Failed to allocate space for the buffer.\n");
        return NULL;
    }

    fread(buffer, sizeof(unsigned char), file_size, file);
    buffer[file_size] = 0;

    return buffer;
}

int write_file(FILE* file, unsigned char* data, int file_size)
{

    if(ferror(file))
    {
        printf("[Error]: Error reading the file.\n");
        return ferror(file);
    }

    fwrite(data, file_size, sizeof(unsigned char), file);
    return 0;
}