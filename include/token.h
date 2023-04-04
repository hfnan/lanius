#ifndef INCLUDE_TOKEN_H
#define INCLUDE_TOKEN_H

#include <str.h>
#include <utils.h>

typedef enum TokenType {
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
    String literal;
} Token;

typedef struct TokenVec {
    Token *array;
    struct Vector;    
} TokenVec;

// token.c
Token *token_new(Token *token, TokenType type, String literal);
TokenVec *tokenvec_new(TokenVec *tokenvec);
Token *next_token(String buf);
#endif