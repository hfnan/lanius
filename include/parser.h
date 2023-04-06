#ifndef INCLUDE_PARSER_H
#define INCLUDE_PARSER_H

#include <lexer.h>
#include <ast.h>

typedef struct Parser {
    union {
        struct Lexer;
        Lexer lexer;
    };

    Token curtoken, peektoken;

    Program *(*parse)(struct Parser *parser);
} Parser;

#endif