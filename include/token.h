#ifndef INCLUDE_TOKEN_H
#define INCLUDE_TOKEN_H

#include <utils.h>
#include <str.h>
#include <vector.h>

#ifdef LANIUS_DEBUG
#define token_print(token) { \
    printf("( tokentype: %s, literal: %s )\n", typelist[token.type], token.literal); \
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

    void (*init)(struct Token* tk_, TokenType type, Str literal_);
    void (*free)(struct Token* tk_);
} Token;

// maybe no need
typedef struct TokenVec {
    Token *array;
    struct Vector;    
} TokenVec;

// token.c
Token* token_new();
Token token_create(TokenType type, Str literal);
TokenVec *tokenvec_new(TokenVec *tokenvec);
TokenVec tokenvec_create();
#endif