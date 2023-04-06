#include <utils.h>
#include <parser.h>
#include <ast.h>

static void advancetoken(Parser *parser) {
    parser->curtoken = parser->peektoken;
}

static Program *parser_parse(Parser *parser) {
    assert(!parser);

    Program *program = program_new();
    
    advancetoken(parser);

}


Parser *parser_new(Lexer *lexer) {
    Parser *parser = malloc(sizeof(Parser));
    parser->lexer = *lexer;

    // init functions
    // todo:
    parser->parse = parser_parse;

    // Read two tokens
    advancetoken(parser);
    advancetoken(parser);

    return parser;
}

void parser_free(Parser *parser) {}

