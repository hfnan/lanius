#ifndef INCLUDE_AST_H
#define INCLUDE_AST_H

#include <str.h>
#include <vector.h>

typedef enum AstType {
    TYPE,
} AstType;

typedef struct SNode {
    AstType asttype;
    Str (*asso_token)();
} SNode;

typedef struct Stmt {
    struct SNode;
} Stmt;

typedef struct StmtVec {
    Stmt *array;
    struct Vector;
} StmtVec;

typedef struct Expression {
    struct SNode;
} Expression;

typedef struct Program {
    struct SNode;
    union {
        struct StmtVec;
        StmtVec stmtvec;
    };    
} Program;

typedef struct AssignStmt {
    
} AssignStmt;

#endif