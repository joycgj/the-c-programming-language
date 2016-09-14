#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int ngetline(char *line, int max);

int main(int argc, const char * argv[]) {
    char line[MAXLINE];
    
    int found = 0;
    
    if (argc != 2) {
        printf("Usage: find pattern\n");
    } else {
        while (ngetline(line, MAXLINE) > 0) {
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
        }
    }
    
    return found;
}

int ngetline(char s[], int max) {
    int c = 0, i;
    
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    
    if (c == '\n') {
        s[i++] = c;
    }
    
    s[i] = '\0';
    return i;
}
