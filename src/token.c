#include <token.h>
#include <utils.h>



Token *token_new(TokenType type, Str literal) {
    Token *token = malloc(sizeof(Token));
    token->type = type;
    token->literal = literal;
    return token;
}

Token token_create(TokenType type, Str literal) {
    return (Token) {.type = type, .literal = literal};
}

TokenVec *tokenvec_new(TokenVec *tokenvec) {
    if (!tokenvec) tokenvec = malloc(sizeof(TokenVec));
    tokenvec->array = realloc(tokenvec->array, sizeof(Token) * BASE_LENGTH);
    tokenvec->len = 0;
    tokenvec->maxlen = BASE_LENGTH;
    return tokenvec;
}

TokenVec tokenvec_create(TokenVec tokenvec) {
    tokenvec.array = realloc(tokenvec.array, sizeof(Token) * BASE_LENGTH);
    if (!tokenvec.array) abort();
    tokenvec.len = 0;
    tokenvec.maxlen = BASE_LENGTH;
    return tokenvec;
}
