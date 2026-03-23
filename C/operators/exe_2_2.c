/*  for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) 
       s[i] = c;
       
    Write a loop equivalent to the for loop above without using && or ||   */

#include <stdio.h>

#define MAXLINE 1000

int getlines(char s[], int lim);

int main()
{
    int len;
    char lines[MAXLINE];

    while((len = getlines(lines, MAXLINE)) > 0){
        printf("%s", lines);
    }    

    return 0;
}

int getlines(char s[], int lim)
{
    int c, i;

    for(i = 0; (i < lim - 1) * ((c = getchar()) != '\n') * (c != EOF); ++i){
        s[i] = c;
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}