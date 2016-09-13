#include <stdio.h>
#include "alloc.h"

int main(int argc, const char * argv[]) {
//    char *s = "how are you";
//    printf("%d\n", nstrlen(s));
    
    char *s2 = "hi";
    while (*s2) {
        printf("OK%d ", *s2);
        s2++;
    }
}