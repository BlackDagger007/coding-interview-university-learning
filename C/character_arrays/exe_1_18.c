/* Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines. */

#include <stdio.h>

#define MAXLINE 1000

int getlines(char s[], int lim);
void removetrailing(char s[], int len);

int main()
{
    int c;
    int len;
    char line[MAXLINE];

    len = 0;
    while((len = getlines(line, MAXLINE)) > 0){
        if(len > 1){
            removetrailing(line, len);
            printf("%s", line);
        }
    }
    
    return 0;
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

void removetrailing(char s[], int len)
{
    int i;

    for(i = len - 1; i >= 0; --i){
        if(s[i] != '\t' && s[i] != ' ' && s[i] != '\n'){
            s[i + 1] = '\n';
            s[i + 2] = '\0';
            break;
        }
    }
}