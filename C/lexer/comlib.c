#include "comlib.h"

char* substr(char* string, int start_pos, int end_pos)
{
    int size = end_pos - start_pos;
    char* buff = (char*)malloc(size+1);

    memcpy(buff, string+start_pos, size);
    buff[size] = 0;
    
    return buff;
}