#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_SIZE 128

typedef struct
{
    int id;
    char* username;
    char* email;
} User;

void display_user(User* user);
User* create_user();
unsigned char* user_to_stream(User* user, int* s_size);
void stream_to_user(unsigned char* stream, int s_size);

#endif