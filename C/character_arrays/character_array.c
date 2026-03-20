#include <stdio.h>

#define MAXLINE 1000

/* A program that returns the longest line from a text*/

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; /* Length of current line */
    int max; /* Max length so far */
    char line[MAXLINE]; /* Current line */
    char longest[MAXLINE]; /* Longest line for far */

    max = 0;
    while((len = getlines(line, MAXLINE)) != 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0){
        printf("\nLongest Line has \"%d\" character(s)", max);
        printf("\n%s", longest);
    }else{
        printf("\nNo data to be processed");
    }

    return 0;
}

/* getlines: Returns the number of characters in a line or 0 if EOF */
int getlines(char s[], int lim)
{
    int i, c;
    i = 0;
    while(i < lim && (c = getchar()) != EOF && c != '\n'){
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

/* copy: Void function to copy the contents of from[] into to[] */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0'){
        ++i;
    }
}