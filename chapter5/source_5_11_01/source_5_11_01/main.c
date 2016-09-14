#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void nqsort(void *v[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

/* nqsort: sort v[left]...v[right] into increasing order */
void nqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    
    void swap(void *v[], int, int);
    
    if (left >= right) {
        return;
    }
    
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    nqsort(v, left, last - 1, comp);
    nqsort(v, last + 1, right, comp);
}


#define MAXLEN 1000 /* max length of any input line */
int ngetline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAXLEN];
    
    while ((len = ngetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    
    return nlines;
}

/* writelines: write output line */
void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}
