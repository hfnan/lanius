#ifndef INCLUDE_TOKEN_H
#define INCLUDE_TOKEN_H

#include <str.h>

typedef enum TokenType {
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
    String literal;
} Token;

typedef struct TokenVec {
    Token *tokenlist;
    int len;
} TokenVec;

#endif