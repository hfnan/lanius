#ifndef INCLUDE_LEXER_H
#define INCLUDE_LEXER_H

#include <token.h>
#include <str.h>

typedef struct Lexer {
    union {
        struct TokenVec;
        TokenVec tokenvec;
    };

    void (*tokenize)(Lexer *lexer, String buf);
    void (*free)(Lexer *lexer); 
} Lexer;

// lexer.c
Lexer *lexer_new(Lexer *lexer, String s);

#endif