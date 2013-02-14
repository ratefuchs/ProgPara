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

int main() {
    yylex();
    node *program = //call parser here
    print(program);
    printf("\n");
    return 0;
}
