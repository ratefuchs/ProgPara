#include <stdio.h>
#include <stdlib.h>
#include "unlambda.h"

void print(node *program) {
    switch (program->type) {
        case APP: printf("("); 
            print(program->left);
            print(program->right); 
            printf(")");
            break;
        case VAR: printf("[%d]",program->var_name);
            break;
        case S: printf("S");
            break;
        case K: printf("K");
            break;
        case I: printf("I");
            break;
    }
}

void error() {
    printf("Parser error!\n");
    exit(1);
}

//insert parser functions here
node * parseP() {
    node * program = (node *) malloc (sizeof(node));
    switch (t.type) {
        case TOKEN_S: yylex();
            program->type = S;
            break;
        case TOKEN_K: yylex();
            program->type = K;
            break;
        case TOKEN_I: yylex();
            program->type = I;
            break;
        case BACKTICK: yylex();
            program->left = parseP();
            program->right = parseP();
            program->type = APP;
            break;
        case LB: yylex();
            if (t.type == VARIABLE) {
                program->type = VAR;
                program->var_name = t.name;
                yylex();
            } else error();
            if (t.type == RB) yylex(); else error();
            break;
        default: error();
    }
    return program;
}

node * parseR() {
    if (t.type != NEWLINE && t.type != RB) {
        node *program = parseP();
        if (t.type != NEWLINE) error();
        return program;
    } else error();
}

int main() {
    yylex();
    node *program = parseR(); //call parser here
    print(program);
    printf("\n");
    return 0;
}
