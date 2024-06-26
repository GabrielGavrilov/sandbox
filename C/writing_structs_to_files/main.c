#include "user.h"
#include "fileio.h"

User* gen_test_user()
{
    User* user = (User*)malloc(sizeof(User));
    
    user->id = 1;
    user->username = "johndoe";
    user->email = "johndoe@gmail.com";

    return user;
}

// input error here
User* create_user()
{
    User* user = (User*)malloc(sizeof(User));

    char username[7];
    char email[7];

    printf("username: ");
    fgets(username, sizeof(username), stdin);

    printf("email: ");
    fgets(email, sizeof(email), stdin);

    user->id = 1;
    user->username = username;
    user->email = email;

    return user;
}

void test_writing_user_to_file()
{
    int size = 0;
    User* user = gen_test_user();
    unsigned char* stream = user_to_stream(user, &size);

    printf("Stream: %d\n", stream);

    FILE* file = open_file("user.txt", "wb");
    write_file(file, stream, size);

    fclose(file);

    printf("Wrote the following user into 'user.txt':\n");
    stream_to_user(stream);
}

void test_reading_user_from_file()
{
    FILE* file = open_file("user.txt", "rb");
    int file_size = get_file_length(file);

    unsigned char* stream = read_file(file, file_size);
 
    printf("stream: %d\nsize: %d\n", stream, file_size);
    stream_to_user(stream);

    fclose(file);
}

int main(int argc, const char* argv[])
{
    // test_writing_user_to_file();
    test_reading_user_from_file();
    return 0;
}