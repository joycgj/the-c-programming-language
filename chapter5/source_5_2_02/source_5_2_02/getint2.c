//  getint2.c
//  练习5-1

#include <stdio.h>
#include <ctype.h>  /* for EOF */
#include "calc.h"

int getint2(int *pn) {
    int c, d, sign;
    
    while (isspace(c = ngetch())) {  /* skip white space */
        ;
    }
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        nungetch(c);    /* it is not a number */
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        d = c;  /* remember sign char */
        if (!isdigit(c = ngetch())) {
            if (c != EOF) {
                nungetch(c);
            }
            nungetch(d);
            return d;
        }
    }
    
    for (*pn = 0; isdigit(c); c = ngetch()) {
        *pn = 10 * *pn + (c - '0');
    }
    
    *pn *= sign;
    
    if (c != EOF) {
        nungetch(c);
    }
    
    return c;
}



