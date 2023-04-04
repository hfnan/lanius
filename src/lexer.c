#include <lexer.h>
#include <token.h>
#include <str.h>
#include <utils.h>

// debug
#include <stdio.h>

static int cur = 0;

static void lexer_free(Lexer *lexer) {
    // todo: free all the attributes in Lexer
}

static void lexer_tokenize(Lexer *lexer, String buf) {

    while (buf[cur]) {
        Token *token = next_token(buf);
        push_back(TokenVec, Token, &(lexer->tokenvec), token);
    }
}

Lexer *lexer_new(Lexer *lexer, String buf) {
    // alloc the manual memory
    if (!lexer) lexer = malloc(sizeof(Lexer)); 
    
    // init the attribute
    lexer->tokenvec = *tokenvec_new(&(lexer->tokenvec));

    // init the function
    lexer->tokenize = lexer_tokenize;
    lexer->free = lexer_free;

    // generate tokens from buffer 
    lexer->tokenize(lexer, buf);

    return lexer;
}

