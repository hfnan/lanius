#ifndef INCLUDE_LEXER_H
#define INCLUDE_LEXER_H

#include <token.h>
#include <str.h>

typedef struct Lexer {
    union {
        struct TokenVec;
        TokenVec tokenvec;
    };

    Str input;
    int str_len, cur;
    char ch;
    
    void (*tokenize)(struct Lexer *lexer);
    Token (*nexttoken)(struct Lexer *lexer);
    void (*free)(struct Lexer *lexer); 
} Lexer;

// lexer.c
Lexer *lexer_new(Str s);

// token.c
Token token_fromd(Lexer *lexer);
Token token_froml(Lexer *lexer);
#endif