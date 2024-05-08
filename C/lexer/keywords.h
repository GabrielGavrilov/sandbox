#ifndef KEYWORDS_H
#define KEYWORDS_H

#include "comlib.h"
#include "tokens.h"

typedef struct
{
    TokenType type;
    char* keyword;
} KeywordType;

extern KeywordType keywords[];

#endif