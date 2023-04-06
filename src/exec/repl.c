#include <str.h>
#include <utils.h>
#include <lexer.h>
#include <parser.h>

static int cnter = 0;
static const char *prompt = "$[%d]: "; // a str array!


void run () {
    
    while (++ cnter) {
        printf(prompt, cnter);

        Str input_;
        
        Lexer* lexer_ = lexer_new();
        
        readline(input_);

        lexer_->init(lexer_, input_);   

#ifdef LEXER_DEBUG
        while (true) {
            Token* tk_ = lexer_->nexttoken(lexer_);
            printf("{ type: %s, literal: %s }\n", typelist[tk_->type], tk_->literal_);
            if (tk_->type == END) {
                tk_->free(tk_);
                break;
            }
            tk_->free(tk_);
        }
#endif

        Parser* parser_ = parser_new();       
        parser_->init(parser_, lexer_); 

        parser_->parse(parser_);
        

        puts("");
    }
}
