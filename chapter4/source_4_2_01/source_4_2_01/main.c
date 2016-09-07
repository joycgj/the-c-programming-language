//
//  main.c
//  source_4_2_01
//
//  Created by chengaojie on 16/9/7.
//  Copyright © 2016年 chengaojie. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

/* rudimentary calculator */
int main(int argc, const char * argv[]) {
    double sum, natof(char []);
    char line[MAXLINE];
    int ngetline(char line[], int max);
    
    sum = 0;
    while (ngetline(line, MAXLINE) > 0) {
        printf("%g\n", sum += natof(line));
    }
    
    return 0;
}

/* atof: convert string s to double */
double natof(char s[]) {
    
    double val, power;
    int i, sign;
    
    for (i = 0; isspace(s[i]); i++) {
        ;
    }
    
    sign = (s[i] == '-') ? -1 : 1;
    
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    
    if (s[i] == '.') {
        i++;
    }
    
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    
    return sign * val / power;
}

/* ngetline: get line into s, return length */
int ngetline(char line[], int max) {
    int c, i;
    
    c = 0;
    i = 0;
    while (--max > 0 && (c=getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}