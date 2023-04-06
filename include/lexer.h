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
    
    void (*init)(struct Lexer* l_, Str in_);
    void (*free)(struct Lexer* l_); 
    Token* (*nexttoken)(struct Lexer* l_);
    void (*nextchar)(struct Lexer* l_);
    char (*peekchar)(struct Lexer* l_);
    Token* (*fromnumber)(struct Lexer* l_);
    Token* (*fromident)(struct Lexer* l_);
} Lexer;

// lexer.c
Lexer* lexer_new();

#endif