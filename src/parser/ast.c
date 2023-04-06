#include <ast.h>

#define prog_stmts(id) ((Stmt*)prog_->array[(id)])

void stmtnode() {}
void exprnode() {}

// program
static Str program_assotoken(Program* prog_) {
    if (prog_->len) 
        return prog_stmts(0)->assotoken(prog_stmts(0));
    else 
        return str_from("");
}


static void program_init(Program* prog_) {
    prog_->asttype = PROGRAM;
    vector_init(prog_->stmtvec);
} 


static void program_free(Program* prog_) {
    vector_free(prog_->stmtvec);
    free(prog_);
}


Program *program_new() {
    Program *prog_ = malloc(sizeof(Program));
    
    // laod function
    prog_->init = program_init;
    prog_->assotoken = program_assotoken;
    prog_->stmtnode = stmtnode;

    return prog_;
}

