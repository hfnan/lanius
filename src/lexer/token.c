#include <utils.h>
#include <token.h>
#include <lexer.h>


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
