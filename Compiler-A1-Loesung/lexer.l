%{
#include <stdio.h>
#include "unlambda.h"

token t;
%}

/* definitions */
Whitespace  [ \r\t]
Var         [0-9]+

%%

S               {t.type = TOKEN_S; return 0;}
K               {t.type = TOKEN_K; return 0;}
I               {t.type = TOKEN_I; return 0;}
\[              {t.type = LB; return 0;}
\]              {t.type = RB; return 0;}
{Var}           {t.type = VARIABLE;
                 sscanf(yytext, "%d", &(t.name)); return 0;}
`               {t.type = BACKTICK; return 0;}
\n              {t.type = NEWLINE; return 0;}
{Whitespace}    /* skip */
.               {printf("Error! Unexpected symbol: %s\n", yytext);
                 exit(1);}

%%
