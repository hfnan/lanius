#include <utils.h>
#include <token.h>
#include <lexer.h>
#include <vector.h>




static void token_init(Token* tk_, TokenType type, Str literal_) {
    if (tk_->literal_) free(tk_->literal_);
    tk_->type = type;
    tk_->literal_ = literal_;
}


static void token_free(Token* tk_) {
    free(tk_->literal_);
    free(tk_);
}


Token* token_new() {
    Token* tk_ = malloc(sizeof(Token));

    // load functions
    tk_->init = token_init;
    tk_->free = token_free;

    return tk_;        
}

Token token_create(TokenType type, Str literal) {
    return (Token) {.type = type, .literal_ = literal};
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



