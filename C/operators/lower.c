/* Implementation for the ctype function "lower" */
#include <stdio.h>

#define MAXLINE 1000

int getlines(char s[], int lim);
char lower(char s);

int main()
{
    int len, i;
    char lines[MAXLINE];

    while((len = getlines(lines, MAXLINE)) > 0){
        printf("OG: %s", lines);

        for(i = 0; lines[i] != '\0'; ++i){
            lines[i] = lower(lines[i]);
        }
        printf("LowG: %s", lines);
    }
}

int getlines(char s[], int lim)
{
    int c, i;

    i = 0;
    while(i < lim - 1 && (c = getchar()) != EOF && c != '\n'){
        s[i] = c;
        ++i;
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

char lower(char s)
{
    if(s >= 'A' && s <= 'Z'){
        s = s + 'a' - 'A';
    }
    return s;
}