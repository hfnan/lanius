#include <utils.h>
#include <parser.h>
#include <ast.h>

static void parser_advancetoken(Parser* p_) {
    p_->ctk_ = p_->ptk_;
    p_->ptk_ = p_->l_->nexttoken(p_->l_);
}

static Stmt* parser_parse_stmt(Parser* p_) {
    return NULL;
}

static Program* parser_parse(Parser* p_) {

    Program *prog_ = program_new();
    prog_->init(prog_);

    while (p_->ctk_->type != END) {
        Stmt* stmt = p_->parse_stmt(p_);
        if (!stmt) {
            // push_back stmt into p_->stmtvec
        }
        token_print(p_->ctk_);
        p_->advancetoken(p_);
    }

    return prog_;
}


static void parser_init(Parser* p_, Lexer* l_) {
    p_->l_ = l_;
    // read two tokens from lexer
    p_->advancetoken(p_);
    p_->advancetoken(p_);
}


static void parser_free(Parser* p_) {
    p_->l_->free(p_->l_);
}


Parser *parser_new() {
    Parser* p_ = malloc(sizeof(Parser));

    // init functions
    p_->init = parser_init;
    p_->free = parser_free;
    p_->parse = parser_parse;
    p_->parse_stmt = parser_parse_stmt;
    p_->advancetoken = parser_advancetoken;

    return p_;
}


