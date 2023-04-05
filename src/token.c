#include <utils.h>
#include <token.h>
#include <lexer.h>



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

TokenVec tokenvec_create() {
    TokenVec tokenvec;
    tokenvec.array = malloc(sizeof(Token) * BASE_LENGTH);
    if (!tokenvec.array) abort();
    tokenvec.len = 0;
    tokenvec.maxlen = BASE_LENGTH;
    return tokenvec;
}

// get token from digit
Token token_fromd(Lexer *lexer) {

}

// get token from letter
Token token_froml(Lexer *lexer) {

}