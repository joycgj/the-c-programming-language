#include <stdio.h>
#include "copy.h"

int main(int argc, const char * argv[]) {
    char src[40];
    char dest[100];
    
    strcpyv4(src, "This is tutorialspoint.com");
    strcpyv4(dest, src);
    
    printf("Final copied string : %s\n", dest);
    
    return(0);
}
