#include <token.h>
#include <utils.h>

Token *token_new(Token *token, TokenType type, String literal) {
    if (!token) token = malloc(sizeof(Token));
    token->type = type;
    token->literal = literal;
    return token;
}

TokenVec *tokenvec_new(TokenVec *tokenvec) {
    if (!tokenvec) tokenvec = malloc(sizeof(TokenVec));
    tokenvec->array = realloc(tokenvec->array, sizeof(Token) * BASE_LENGTH);
    tokenvec->len = 0;
    tokenvec->maxlen = BASE_LENGTH;
    return tokenvec;
}

Token *next_token(String buf) {
    // todo
}