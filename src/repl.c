#include <utils.h>
#include <str.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lexer.h>

static int cnter = 0;
static const Str prompt = "$[%d]: ";
static Str input;


void run () {
    
    while (++ cnter) {
        readline(input, prompt, cnter);

        Lexer *lexer = lexer_new(input);   

        lexer->free(lexer);     
        puts("");
    }
}
