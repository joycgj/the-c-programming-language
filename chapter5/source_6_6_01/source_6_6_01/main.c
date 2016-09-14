#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101
#define MAX 101

struct nlist {          /* table entry */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;
    
    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;  /* found */
        }
    }
    
    return NULL; /* not found */
}

struct nlist *lookup(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else { /* already there */
        free((void *) np->defn); /* free previous defn */
    }
    
    if ((np->defn = strdup(defn)) == NULL) {
        return NULL;
    }
    
    return np;
}


void print_usage() {
    printf("\n--- BE AWARE: THIS TEST PROGRAM HAS NO ERROR TREATMENT ---\n\n");
    printf("i)nstall(name,text)  l)ookup(name)  \n");
    printf("Test program usage: H)Help  Q)Quit\n");
}

int main(int argc, const char * argv[]) {
    char c;
    char tmp_name[MAX], tmp_def[MAX], tmp_result[MAX];
    struct nlist *result;
    
    char *prompt = ">";
    
    print_usage();
    printf("%s", prompt);
    
    while ((c = getchar())) {
        switch (c) {
            case 'i': // install
                scanf("%s %s", tmp_name, tmp_def); // read input
                install(tmp_name, tmp_def);
                break;
            
            case 'l': // lookup
                scanf("%s", tmp_result); // read input
                result = lookup(tmp_result);
                
                if (result != NULL) {
                    printf("%s: %s \n",result->name, result->defn);
                } else {
                    printf("Pattern was not found.\n");
                }
                break;
                
            case 'H': // Help
                print_usage();
                break;
                
            case 'Q': // Quit
                return 0;
                
            default:
                print_usage();
                break;
        }
        while (getchar() != '\n') {} /* skip end of line */
        printf("%s", prompt);
    }
}
