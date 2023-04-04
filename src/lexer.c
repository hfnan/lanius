#include <lexer.h>
#include <token.h>
#include <str.h>
#include <utils.h>

Lexer *lexer_new(Lexer *lexer, String buf) {
    // alloc the manual memory
    if (!lexer) lexer = malloc(sizeof(Lexer)); 
    
    // init the attribute
    lexer->tokenlist = malloc(sizeof(Token) * BASE_LENGTH);
    lexer->len = 0;

    // init the function
    lexer->tokenize = lexer_tokenize;
    lexer->free = lexer_free;

    // generate tokens from buffer 
    lexer->tokenize(lexer, buf);

    return lexer;
}

static void lexer_free(Lexer *lexer) {
    // todo: free all the attributes in Lexer
}

static void lexer_tokenize(Lexer *lexer, String buf) {

}