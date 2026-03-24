/* Implementation for the function atoi which converts a string of integers to it's numerical value */

#include <stdio.h>
#define MAXLINE 1000

int getlines(char s[], int lim);
int atoi(char s[]);

int main()
{
    int len;
    char lines[MAXLINE];

    while((len = getlines(lines, MAXLINE)) > 0){
        printf("Input 'string' is '%s'\n", lines);
        printf("Input + 20 is %d\n", atoi(lines) + 20);
    }

    return 0;
}

int getlines(char s[], int lim){
    int c, i;

    
    i = 0;
    printf("Enter a string of numbers only\n");
    while(i < lim - 1 && (c = getchar()) != EOF && c != '\n' && c >= '0' && c <= '9'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

int atoi(char s[]){
    int i, n;

    i = n = 0;
    while(s[i] != '\0'){
        n = 10 * n + (s[i] - '0');
        ++i;
    }

    return n;
}