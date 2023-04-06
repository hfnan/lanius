#include <utils.h>
#include <lexer.h>
#include <str.h>
#include <vector.h>

#define token_set(tk_, type, literal_) {    \
    (tk_)->init((tk_), (type), (literal_)); \
}

// get token from digit
static Token* lexer_fromnumber(Lexer* l_) {
    Str literal_ = str_fromc(l_->ch);
    while (isdigit(l_->peekchar(l_))) {
        l_->nextchar(l_);
        str_extend(literal_, "%s%c", literal_, l_->ch);
    }
    Token *tk_ = token_new();
    token_set(tk_, NUMBER, literal_);
    return tk_;
}


// get token from letter
// todo: maybe this function and previous function can be compounded
static Token* lexer_fromident(Lexer* l_) {
    Str literal_ = str_fromc(l_->ch);
    while (islod(l_->peekchar(l_))) {
        l_->nextchar(l_);
        str_extend(literal_, "%s%c", literal_, l_->ch);
    }
    Token *tk_ = token_new();
    token_set(tk_, NUMBER, literal_);
    return tk_;
}


static void lexer_nextchar(Lexer* l_) {
    assert(l_ != NULL);
    if (l_->cur >= l_->str_len) 
        l_->ch = 0;
    else 
        l_->ch = l_->str_[l_->cur ++ ]; 
}

static char lexer_peekchar(Lexer* l_) {
    assert(l_ != NULL);
    if (l_->cur >= l_->str_len) 
        return 0;
    return l_->str_[l_->cur];
}

static void omitblank(Lexer* l_) {
    assert(l_ != NULL);
    while (iswhite(l_->ch)) 
        l_->nextchar(l_);
}


// there is no need for Token to use the pointer
// todo: add more tokens
static Token* lexer_nexttoken(Lexer* l_) {
    // omit the black characters 
    omitblank(l_);

    char ch = l_->ch;

    Token* tk_ = token_new();
    tk_->init(tk_, ILLEGAL, str_fromc(ch));

    if (isdigit(ch)) {
        tk_ = l_->fromnumber(l_);
    }
    else if (isletter(ch)) {
        tk_ = l_->fromident(l_);
    }
    else if (ch == '#') {
        token_set(tk_, HASH, str_fromc(ch));
    }
    else if (ch == '$') {
        token_set(tk_, DOLLAR, str_fromc(ch));
    }
    else if (ch == '=') {
        token_set(tk_, ASSIGN, str_fromc(ch));
    }
    else if (ch == '+') {
        token_set(tk_, ADD, str_fromc(ch));
    }
    else if (ch == '-') {
        token_set(tk_, SUB, str_fromc(ch));
    }
    else if (ch == '*') {
        token_set(tk_, STAR, str_fromc(ch));
    }
    else if (ch == '/') {
        token_set(tk_, SLASH, str_fromc(ch));
    }
    else if (ch == '%') {
        token_set(tk_, PERCENT, str_fromc(ch));
    }
    else if (ch == '(') {
        token_set(tk_, LPAREN, str_fromc(ch));
    }
    else if (ch == ')') {
        token_set(tk_, RPAREN, str_fromc(ch));
    }
    else if (ch == '{') {
        token_set(tk_, LBRACE, str_fromc(ch));
    }
    else if (ch == '}') {
        token_set(tk_, RBRACE, str_fromc(ch));
    }
    else if (ch == ',') {
        token_set(tk_, DELIM, str_fromc(ch));
    }
    else if (ch == 0) {
        token_set(tk_, END, str_from(""));
    }
    else {
        token_set(tk_, ILLEGAL, str_fromc(ch));
    }
    l_->nextchar(l_);
    return tk_;
}

static void lexer_init(Lexer* l_, Str in_) {
    // init the input string
    l_->str_ = in_;
    l_->cur = 0;
    l_->str_len = strlen(in_);    
    l_->nextchar(l_);
}


// a strange function: maybe no need  
static Lexer* lexer_copy() {}


// when Lexer changed, don't forget to inspect this function
static void lexer_free(Lexer *l_) {
    // there are all plains in lexer except the function pointers
    free(l_);
}


// malloc the memory for the pointer and load the functions
// all functions but this are static
Lexer* lexer_new() {
    
    // malloc the memory 
    Lexer* l_ = malloc(sizeof(Lexer));
    
    // load the functions
    l_->init =          lexer_init;
    l_->free =          lexer_free;
    l_->nexttoken =     lexer_nexttoken; // maybe need not to public it for others: delete it from here!
    l_->nextchar =      lexer_nextchar;
    l_->peekchar =      lexer_peekchar;
    l_->fromnumber =    lexer_fromnumber;
    l_->fromident =     lexer_fromident;
    
    return l_;
}