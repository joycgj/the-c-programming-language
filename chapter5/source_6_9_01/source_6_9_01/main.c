#include <stdio.h>

#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

int main(int argc, const char * argv[]) {
    unsigned int flags = 1; // all bits are off, but not the lowest one
    printf("%u\n", flags);
    
    flags |= EXTERNAL | STATIC; // turns off EXTERNAL and STATIC bits in flags
    printf("%u\n", flags);
    
    flags &= ~(EXTERNAL | STATIC); // turns off EXTERNAL and STATIC bits in flags
    printf("%u\n", flags);
}
