/* Write a program to ``fold'' long input lines into two or more shorter lines after 
the last non-blank character that occurs before the n-th column of input. Make sure your 
program does something intelligent with very long lines, and if there are no blanks or tabs 
before the specified column. */

#include <stdio.h>

#define MAXCOL 15
#define MAXLINE 1000

int getlines(char s[], int lim);
void fold(char from[], char to[], int maxcol);

int main()
{
    int len;
    char lines[MAXLINE];
    char res[MAXLINE];

    while((len = getlines(lines, MAXLINE)) > 0){
        fold(lines, res, MAXCOL);
        printf("%s", res);
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

void fold(char from[],char to[], int maxcol)
{
    int i, j, k;

    i = j = k = 0;
    while(from[i] != EOF && from[i] != '\n'){
        if(k > 0 && (k + 1) % maxcol == 0){
            if(from[i] != ' ' && from[i - 1] == ' '){
                to[j] = '\n';
                to[++j] = from[i];
            }else if(from[i] != ' ' && from[i + 1] != ' '){
                to[j] = '-';
                to[++j] = '\n';
                to[++j] = from[i];
            }else if(from[i] != ' ' && from[i + 1] == ' '){
                to[j] = from[i];
                to[++j] = '\n';
                ++i;
            }else{
                to[j] = '\n';
            }
        }else{
            to[j] = from[i];
        }
        ++i;
        ++j;
        ++k;
    }
    
    to[j] = '\n';
    to[++j] = '\0';
}