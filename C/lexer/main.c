#include "comlib.h"
#include "tokens.h"
#include "keywords.h"
#include "lexer.h"

int main(int argc, char** argv)
{
    char str[] = "print \"Hello, World!\" +- * / / print";
    Lexer* lexer = init_lexer(str);
    Token token = get_next_token_in_lexer(lexer);

    while(token.type != TOKEN_EOF)
    {
        printf("%d :: %s\n", token.type, token.value);
        token = get_next_token_in_lexer(lexer);
    }

    free_lexer(lexer);
    return 0;
}