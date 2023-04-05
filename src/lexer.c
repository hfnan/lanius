#include <utils.h>
#include <lexer.h>
#include <str.h>
#include <vector.h>


static void nextchar(Lexer *lexer) {
    assert(lexer != NULL);
    if (lexer->cur >= lexer->str_len) 
        lexer->ch = 0;
    else 
        lexer->ch = lexer->input[lexer->cur ++ ]; 
}

static char peekchar(Lexer *lexer) {
    assert(lexer != NULL);
    if (lexer->cur >= lexer->str_len) 
        return 0;
    return lexer->input[lexer->cur];
}

static void omitblank(Lexer *lexer) {
    assert(lexer != NULL);
    while (iswhite(lexer->ch)) 
        nextchar(lexer);
}

Bool isletter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_';
}

// when Lexer changed, don't forget to inspect this function
static void lexer_free(Lexer *lexer) {
    free(lexer->array);
    free(lexer);
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

// there is no need for Token to use the pointer
// todo: add more tokens
static Token lexer_nexttoken(Lexer *lexer) {
    // omit the black characters 
    omitblank(lexer);

    char ch = lexer->ch;

    Token token = token_create(ILLEGAL, str_fromc(ch));

    if (isdigit(ch)) {
        token = token_fromd(lexer);
    }
    else if (isletter(ch)) {
        token = token_froml(lexer);
    }
    else if (ch == '#') {
        token = token_create(HASH, str_fromc(ch));
    }
    else if (ch == '$') {
        token = token_create(DOLLAR, str_fromc(ch));
    }
    else if (ch == '=') {
        token = token_create(ASSIGN, str_fromc(ch));
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
    else if (ch == '%') {
        token = token_create(PERCENT, str_fromc(ch));
    }
    else if (ch == '(') {
        token = token_create(LPAREN, str_fromc(ch));
    }
    else if (ch == ')') {
        token = token_create(RPAREN, str_fromc(ch));
    }
    else if (ch == '{') {
        token = token_create(LBRACE, str_fromc(ch));
    }
    else if (ch == '}') {
        token = token_create(RBRACE, str_fromc(ch));
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
    lexer->nextchar = nextchar;
    lexer->peekchar = peekchar;

#ifdef LANIUS_DEBUG
    printf("lexer.c/lexer_new: before tokenize complete!\n");
#endif
 
    // generate tokens from buffer 
    lexer->tokenize(lexer);

    return lexer;
}

