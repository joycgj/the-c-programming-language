/* Example using strcpy by TechOnTheNet.com */

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    /* Create an example variable capable of holding 50 characters */
    char example[50];
    char *p;
    
    /* Copy the string "TechOnTheNet.com knows strcpy!" into the example variable */
    strcpy(example, "TechOnTheNet.com knows strcpy!");
    
    strcpy(p, "hi, chengaojie");
    
    /* Display the contents of the example variable to the screen */
    printf("%s\n", example);
    
    printf("%s\n", p);
    
    return 0;
}
