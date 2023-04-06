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
        
        Lexer* l_ = lexer_new();
        
        readline(input_)

        printf("%s\n", input_);
        l_->init(l_, input_);   

        while (true) {
            Token* tk_ = l_->nexttoken(l_);
            printf("{ type: %s, literal: %s }\n", typelist[tk_->type], tk_->literal_);
            if (tk_->type == END) {
                tk_->free(tk_);
                break;
            }
            tk_->free(tk_);
        }
        

        puts("");
    }
}
