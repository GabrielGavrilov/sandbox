#ifndef LEXER_H
#define LEXER_H

#include "comlib.h"
#include "tokens.h"
#include "keywords.h"

typedef struct 
{
    int src_size;
    int curr_pos;
    char* src;
    char curr_char;
} Lexer;

Lexer* init_lexer(char* src);
void free_lexer(Lexer* lexer);
void advance_lexer(Lexer* lexer);
char peek_lexer(Lexer* lexer);
Token get_next_token_in_lexer(Lexer* lexer);

#endif