#ifndef INCLUDE_PARSER_H
#define INCLUDE_PARSER_H

#include <lexer.h>
#include <ast.h>

typedef struct Parser {
    Lexer* l_;

    Token* ctk_,* ptk_;

    void (*init)(struct Parser* self_, Lexer* l_);
    void (*free)(struct Parser* self_);
    Program* (*parse)(struct Parser* self_);
    Stmt* (*parse_stmt)(struct Parser* self_);
    void (*advancetoken)(struct Parser* self_);
} Parser;

// parser.c
Parser* parser_new();

#endif