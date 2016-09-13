#include <stdio.h>
#include <ctype.h>  /* for EOF */
#include "calc.h"

/* getint:  get next integer from input into *pn
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the input.
 */
int getint(int *pn) {
    int c, sign;
    
    while (isspace(c = ngetch())) {  /* skip white space */
        ;
    }
           
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        nungetch(c);    /* it is not a number */
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = ngetch();
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


