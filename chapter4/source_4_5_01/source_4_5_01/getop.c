#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    
    int i, c;
    
    while ((s[0] = c = ngetch()) == ' ' || c == '\t') {
        ;
    }
    
    s[1] = '\0';
    
    if (!isdigit(c) && c != '.') {
        return c;   /* not a number */
    }
    
    i = 0;
    if (isdigit(c)) {   /* collect integer part */
        while (isdigit(s[++i] = c = ngetch())) {
            ;
        }
    }
    
    if (c == '.') {     /* collect fraction part */
        while (isdigit(s[++i] = c = ngetch())) {
            ;
        }
    }
    s[i] = '\0';
    
    if (c != EOF) {
        nungetch(c);
    }
    
    return NUMBER;
}

