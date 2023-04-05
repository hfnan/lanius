#ifndef INCLUDE_TOKEN_H
#define INCLUDE_TOKEN_H

#include <utils.h>
#include <str.h>

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
    "ASSIGN",
    "HASH",
    
    "NUMBER",
    
    "LPAREN",
    "RPAREN",
    "ADD",
    "SUB",
    "STAR",
    "SLASH",
};

#endif


typedef enum TokenType {
    ILLEGAL,
    END,
    DELIM,

    KEYWORD,
    SYMBOL,
    ASSIGN,
    HASH,

    NUMBER,

    LPAREN,
    RPAREN,
    ADD,
    SUB,
    STAR,
    SLASH,
} TokenType;

typedef struct Token {
    TokenType type;
    Str literal;
} Token;

typedef struct TokenVec {
    Token *array;
    struct Vector;    
} TokenVec;

// token.c
Token *token_new(TokenType type, Str literal);
Token token_create(TokenType type, Str literal);
TokenVec *tokenvec_new(TokenVec *tokenvec);
TokenVec tokenvec_create();
#endif