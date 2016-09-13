#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];  /* buffer for nungetch */
static int bufp = 0;   /* next free position in buf */

int ngetch(void) {   /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void nungetch(int c) {  /* push character back on input */
    if (bufp >= BUFSIZE) {
        printf("nungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
