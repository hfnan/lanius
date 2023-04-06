#ifndef INCLUDE_TOKEN_H
#define INCLUDE_TOKEN_H

#include <utils.h>
#include <str.h>
#include <vector.h>

#ifdef LANIUS_DEBUG
#define token_print(token_) { \
    printf("( type: %s, literal: %s )\n", typelist[(token_)->type], (token_)->literal_); \
}

static Str typelist[] = {
    "ILLEGAL",
    "END",
    "DELIM",
    "KEYWORD",
    "SYMBOL",
    "NUMBER",

    "ASSIGN",
    "HASH",
    "DOLLAR",
    "ADD",
    "SUB",
    "STAR",
    "SLASH",
    "PERCENT",
    
    "LT",         
    "GT",         
    "LE",         
    "GE",         
    "EQUAL",      
    "NE",         

    "LPAREN",
    "RPAREN",
    "LBRACE",
    "RBRACE",
};

#endif


typedef enum TokenType {
    // origin
    ILLEGAL,
    END,
    DELIM,
    KEYWORD,
    SYMBOL,
    NUMBER,

    // operator
    ASSIGN,     // => =
    HASH,       // => #
    DOLLAR,     // => $
    ADD,        // => +
    SUB,        // => -
    STAR,       // => *
    SLASH,      // => /
    PERCENT,    // => %

    // maybe not be used
    LT,         // => <
    GT,         // => >
    LE,         // => <=
    GE,         // => >=
    EQUAL,      // => ==
    NE,         // => !=

    LPAREN,     // => (
    RPAREN,     // => )
    LBRACE,     // => {
    RBRACE,     // => }
} TokenType;


typedef struct Token {
    TokenType type;
    Str literal_;

    void (*init)(struct Token* self_, TokenType type, Str literal_);
    void (*free)(struct Token* self_);
} Token;

// token.c
Token* token_new();
#endif