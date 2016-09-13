#include <stdio.h>
#include "calc.h"

int main(int argc, const char * argv[]) {
    int x, retval;
//    int* px;
//    px = &x;
    retval = getint(&x);
    printf("retval=%d, x=%d\n", retval, x);
    
    retval = getint2(&x);
    printf("retval=%d, x=%d\n", retval, x);
    return 0;
}
