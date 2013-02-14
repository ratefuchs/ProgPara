%{
#include <stdio.h>
#include "unlambda.h"

token t;
%}

/* definitions */
Whitespace  [ \r\t]

%%

\n              {t.type = NEWLINE; return 0;}
{Whitespace}    /* skip */
.               {printf("Error! Unexpected symbol: %s\n", yytext);
                 exit(1);}

%%
