/* strcpyv1: copy t to s; array subscript version */
void strcpyv1(char *s, char *t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0') {
        i++;
    }
}

/* strcpyv2: copy t to s; pointer version */
void strcpyv2(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/* strcpyv3: copy t to s; pointer version 2 */
void strcpyv3(char *s, char *t) {
    while ((*s++ = *t++) != '\0') {
        ;
    }
}

/* strcpyv4: copy t to s; pointer version 3 */
void strcpyv4(char *s, char *t) {
    while ((*s++ = *t++)) {
        ;
    }
}
