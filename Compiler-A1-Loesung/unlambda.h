#ifndef TOKEN
#define TOKEN

typedef enum token_type {
    TOKEN_S,
    TOKEN_K,
    TOKEN_I,
    NEWLINE,
    WHITESPACE,
    VARIABLE,
    BACKTICK,
    LB,
    RB,
} token_type;

typedef struct token {
    token_type type;
    int name;
} token;

typedef enum node_type {
    S,
    K,
    I,
    APP,
    VAR,
} node_type;

typedef struct node {
    node_type type;
    struct node *left;
    struct node *right;
    int var_name;
} node;

extern token t;

#endif
