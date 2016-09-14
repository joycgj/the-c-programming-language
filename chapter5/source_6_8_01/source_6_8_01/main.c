#include <stdio.h>
#define MAX 100

int main(int argc, const char * argv[]) {
    union u_tag {
        char cval; // added by BH
        float fval;
        int ival;
        char *sval;
    } u;
    
    char msg[MAX];
    
    printf("> Insert resp. a character, integer, float and word: ");
    
    scanf("%c", &u.cval);
    printf("%X, %d Byte,  %c\n", &u.cval, sizeof(u.cval), u.cval);
    
    scanf("%i", &u.ival);
    printf("%X, %d Bytes, %d\n", &u.ival, sizeof(u.ival), u.ival);
    
    scanf("%f", &u.fval);
    printf("%X, %d Bytes, %f\n", &u.fval, sizeof(u.fval), u.fval);
    
    scanf("%s", msg);
    u.sval = msg;
    printf("%X, %d Bytes, %s, address of the word: %X\n", &u.sval, sizeof(u.sval), u.sval, &msg);
}
