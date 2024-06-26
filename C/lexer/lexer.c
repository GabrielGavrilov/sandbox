#include "lexer.h"

Lexer* init_lexer(char* src)
{
    Lexer* lexer = (Lexer*)malloc(sizeof(Lexer));
    
    lexer->src = src;
    lexer->curr_pos = -1;
    lexer->src_size = strlen(src);

    advance_lexer(lexer);
    return lexer;
}

void free_lexer(Lexer* lexer)
{
    free(lexer);
    lexer->src = NULL;
    lexer = NULL;
}

void advance_lexer(Lexer* lexer)
{
    lexer->curr_pos++;

    if(lexer->curr_pos >= lexer->src_size)
        lexer->curr_char = '\0';
    else
        lexer->curr_char = lexer->src[lexer->curr_pos];
}

char peek_lexer(Lexer* lexer)
{
    if(lexer->curr_pos+1 >= lexer->src_size)
        return '\0';

    return lexer->src[lexer->curr_pos+1];
}

void skip_whitepsace(Lexer* lexer)
{
    while(lexer->curr_char == ' ' || lexer->curr_char == '\t')
        advance_lexer(lexer);
}

Token create_token(char* value, TokenType type)
{
    Token token;
    token.type = type;
    token.value = value;
    return token;
}

Token create_string_token(Lexer* lexer)
{
    Token token;
    advance_lexer(lexer);
    int start_pos = lexer->curr_pos;

    while(lexer->curr_char != '\"')
        advance_lexer(lexer);

    token.type = TOKEN_STRING;
    token.value = substr(lexer->src, start_pos, lexer->curr_pos);

    return token;
}

TokenType get_keyword_type(char* value)
{
    for (int i = 0; i < sizeof(keywords[0])/sizeof(KeywordType); i++)
    {
        if(!strcmp(value, keywords[i].keyword))
            return keywords[i].type;
    }

    return TOKEN_IDENTIFIER;
}

Token create_keyword_token(Lexer* lexer)
{
    Token token;
    int start_pos = lexer->curr_pos;

    while (isalpha(peek_lexer(lexer)))
        advance_lexer(lexer);

    char* value = substr(lexer->src, start_pos, lexer->curr_pos + 1);
    token.type = get_keyword_type(value);
    token.value = value;

    return token;
}

Token get_next_token_in_lexer(Lexer* lexer)
{
    skip_whitepsace(lexer);
    Token token;

    if(lexer->curr_char == '+')
        token = create_token("+", TOKEN_PLUS);
    
    else if(lexer->curr_char == '-')
        token = create_token("-", TOKEN_MINUS);
    
    else if(lexer->curr_char == '*')
        token = create_token("*", TOKEN_ASTERISK);
    
    else if(lexer->curr_char == '/')
        token = create_token("/", TOKEN_SLASH);

    else if(lexer->curr_char == '\"')
        token = create_string_token(lexer);

    else if(isalpha(lexer->curr_char))
        token = create_keyword_token(lexer);

    else if(lexer->curr_char == '\0')
        token = create_token(NULL, TOKEN_EOF);

    advance_lexer(lexer);
    return token;
}