#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 10

char buf[BUFSIZE];  /* buffer for myungetch */
int bufp = 0;       /* next free position in buf */

int mygetch(void);
void myungetch(int);
int getint(int *pn);

int main(int argc, const char * argv[]) {
    while (bufp < BUFSIZE) {
        buf[bufp++] = '2';
    }
    
    int result;
    int hi = getint(&result);
    printf("%d, %d", hi, result);
    return 0;
}

/* get a (possibly pushed-back) character */
int mygetch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void myungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("myungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    
    /* skip white space */
    while (isspace(c = mygetch())) {
        ;
    }
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        myungetch(c);   /* it is not a number */
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = mygetch();
    }
    
    for (*pn = 0; isdigit(c); c = mygetch()) {
        *pn = 10  * *pn + (c - '0');
    }
    
    *pn *= sign;
    
    if (c != EOF) {
        myungetch(c);
    }
    return c;
}
