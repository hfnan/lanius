#include <utils.h>
#include <lexer.h>
#include <str.h>

// debug
#include <stdio.h>
#include <assert.h>

static void nextchar(Lexer *lexer) {
    assert(lexer != NULL);
    if (lexer->cur >= lexer->str_len) 
        lexer->ch = 0;
    else 
        lexer->ch = lexer->input[lexer->cur ++ ]; 
}

static void omitblank(Lexer *lexer) {
    assert(lexer != NULL);
    while (iswhite(lexer->ch)) 
        nextchar(lexer);
}

static Bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

static Bool isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

static void lexer_free(Lexer *lexer) {
    // todo: free all the attributes in Lexer
}

static void lexer_tokenize(Lexer *lexer) {
#ifdef LANIUS_DEBUG
    printf("lexer.c/lexer_tokenize: \n");
    printf("input string: '%s'\n", lexer->input);
#endif

    while (true) {
        Token token = lexer->nexttoken(lexer);
#ifdef LANIUS_DEBUG
        token_print(token);
#endif

        push_back(Token, &(lexer->tokenvec), &token);
        if (token.type == END) break;
    }
}

// there is no need for token to use the pointer
static Token lexer_nexttoken(Lexer *lexer) {
    // omit the black characters 
    omitblank(lexer);

    char ch = lexer->ch;

    Token token = token_create(ILLEGAL, str_fromc(ch));

    if (isDigit(ch)) {
        token = token_fromd(lexer);
    }
    else if (isLetter(ch)) {
        token = token_froml(lexer);
    }
    else if (ch == '+') {
        token = token_create(ADD, str_fromc(ch));
    }
    else if (ch == '-') {
        token = token_create(SUB, str_fromc(ch));
    }
    else if (ch == '*') {
        token = token_create(STAR, str_fromc(ch));
    }
    else if (ch == '/') {
        token = token_create(SLASH, str_fromc(ch));
    }
    else if (ch == '(') {
        token = token_create(LPAREN, str_fromc(ch));
    }
    else if (ch == ')') {
        token = token_create(RPAREN, str_fromc(ch));
    }
    else if (ch == ',') {
        token = token_create(DELIM, str_fromc(ch));
    }
    else if (ch == 0) {
        token = token_create(END, str_from(""));
    }
    else {
        token = token_create(ILLEGAL, str_fromc(ch));
    }
    nextchar(lexer);
    return token;
}

Lexer *lexer_new(Str input) {
    // alloc lexer 
    Lexer *lexer = malloc(sizeof(Lexer));
    
    // create the attribute
    // use _create to avoid memory leak 
    lexer->tokenvec = tokenvec_create();

    // init the input string
    lexer->input = input;
    lexer->cur = 0;
    lexer->str_len = strlen(input);    
    nextchar(lexer);

    // init the function
    lexer->tokenize = lexer_tokenize;
    lexer->nexttoken = lexer_nexttoken; // maybe need not to public it for others: delete it from here!
    lexer->free = lexer_free;

#ifdef LANIUS_DEBUG
    printf("lexer.c/lexer_new: before tokenize complete!\n");
#endif
 
    // generate tokens from buffer 
    lexer->tokenize(lexer);

    return lexer;
}

