#ifndef INCLUDE_AST_H
#define INCLUDE_AST_H

#include <str.h>
#include <vector.h>

typedef enum AstType {
    PROGRAM,
} AstType;

// every astNode should put this struct at the top of their struct
typedef struct SNode {
    AstType asttype;
    Str (*assotoken)(void* self_);
} SNode;


typedef struct Stmt {
    struct SNode;
    void (*stmtnode)();
} Stmt;


typedef struct Expr {
    struct SNode;
    void (*exprnode)();
} Expr;


typedef struct Program {
    struct Stmt;
    union {
        struct Vector;
        Vector stmtvec;
    };

    void (*init)(struct Program* self_);
} Program;

typedef struct AssignStmt {
    
} AssignStmt;


// ast.c
void stmtnode();
void exprnode();

Program* program_new();

#endif