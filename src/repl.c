#include <utils.h>
#include <str.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lexer.h>

static int cnter = 0;
static const String prompt = "$[%d]: ";
static String buf;


void run () {
    
    while (++ cnter) {
        readline(buf, prompt, cnter);

        Lexer *lexer = lexer_new(lexer, buf);   

        lexer->free(lexer);     
        puts("");
    }
}
