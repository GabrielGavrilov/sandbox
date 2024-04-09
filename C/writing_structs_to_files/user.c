#include "user.h"

void display_user(User* user)
{
    printf("\nid: %d\nusername: %s\nemail: %s\n", user->id, user->username, user->email);
}


unsigned char* user_to_stream(User* user, int* s_size)
{
    *s_size = sizeof(int) // id
                + sizeof(int) // store username length
                + strlen(user->username) // username
                + sizeof(int) // store email length
                + strlen(user->email); // email
    
    unsigned char* stream = (unsigned char*)malloc(*s_size);

    *((int*)stream) = user->id;
   
    *((int*)(stream + sizeof(int))) = strlen(user->username);
    memcpy(stream + sizeof(int) * 2, user->username, strlen(user->username));
    
    *((int*)(stream + (sizeof(int) * 2 + strlen(user->username)))) = strlen(user->email);
    memcpy(stream + (sizeof(int) * 3 + strlen(user->username) ), user->email, strlen(user->email));
    
    return stream;
}

void stream_to_user(unsigned char* stream)
{
    int id = *((int*)stream);
    int username_size = *((int*)(stream + sizeof(int)));
    int email_size = *((int*)(stream + (sizeof(int) * 2 + username_size)));

    char* username = (char*)malloc(username_size + 1);
    memcpy(username, (char*)stream + sizeof(int) * 2, username_size);
    username[username_size] = 0;

    char* email = (char*)malloc(email_size + 1);
    memcpy(email, (char*)stream + sizeof(int) * 3 + username_size, email_size);
    email[email_size] = 0;

    printf("\nid: %d\n", id);
    printf("username size: %d\n", username_size);
    printf("username: %s\n", username);
    printf("email size: %d\n", email_size);
    printf("email: %s\n", email);
}