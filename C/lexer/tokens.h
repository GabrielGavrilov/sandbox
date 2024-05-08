#ifndef TOKENS_H
#define TOKENS_H

typedef enum
{
    TOKEN_EOF = 0,
    TOKEN_NEWLINE = 1,

    TOKEN_PLUS = 100,
    TOKEN_MINUS = 101,
    TOKEN_ASTERISK = 102,
    TOKEN_SLASH = 103,

    TOKEN_IDENTIFIER = 300,
    TOKEN_STRING = 301,

    TOKEN_PRINT = 401
} TokenType;

typedef struct 
{
    TokenType type;
    char* value;
} Token;

#endif