#ifndef LEXER_H
#define LEXER_H

#include "comlib.h"

typedef enum
{
    TOKEN_EOF = 0,
    TOKEN_NEWLINE = 1,

    TOKEN_PLUS = 100,
    TOKEN_MINUS = 101,
    TOKEN_ASTERISK = 102,
    TOKEN_SLASH = 103,

    TOKEN_STRING = 300
    
} TokenType;

typedef struct 
{
    TokenType type;
    char* value;
} Token;

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