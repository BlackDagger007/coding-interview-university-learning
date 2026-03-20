/* Write a program to print all input lines that are longer than 80 characters. */
#include <stdio.h>

#define MAXLINE 1000
#define MAXCHAR 10

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    char line[MAXLINE];
    
    while((len = getlines(line, MAXLINE)) > 0){
        if(len > MAXCHAR){
            printf("\n>=%d: %s", MAXCHAR, line);
        }
    }

    return 0;
}


int getlines(char s[], int lim)
{
    int i, c;

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