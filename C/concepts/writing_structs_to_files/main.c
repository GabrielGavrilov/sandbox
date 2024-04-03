#include "user.h"

int main(int argc, const char* argv[])
{
    int s_size = 0;
    int* ptr_size = &s_size;
    User* user = (User*)malloc(sizeof(User));

    user->id = 1;
    user->username = "johndoe";
    user->email = "johndoe@gmail.com";

    display_user(user);

    unsigned char* stream = user_to_stream(user, ptr_size);
    stream_to_user(stream, s_size);

    return 0;
}