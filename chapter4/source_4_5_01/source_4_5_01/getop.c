#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    
    int c, i;
    static int lastc = 0;
    
    if (lastc == 0) {
        c = ngetch();
    } else {
        c = lastc;
        lastc = 0;
    }
    
    while ((s[0] = c) == ' ' || c == '\t') {
        c = ngetch();
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
        lastc = c;
    }
    
    return NUMBER;
}

