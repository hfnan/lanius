#ifndef INCLUDE_LEXER_H
#define INCLUDE_LEXER_H

#include <token.h>
#include <str.h>


/**
 * A pointer struct 
 * Using for lexical analysis
 */
typedef struct Lexer {
    
    Str str_;
    int str_len, cur;
    char ch;
    
    void (*init)(struct Lexer* self_, Str in_);
    void (*free)(struct Lexer* self_); 
    Token* (*nexttoken)(struct Lexer* self_);
    void (*nextchar)(struct Lexer* self_);
    char (*peekchar)(struct Lexer* self_);
    Token* (*fromnumber)(struct Lexer* self_);
    Token* (*fromident)(struct Lexer* self_);
} Lexer;

// lexer.c
Lexer* lexer_new();

#endif