/* Write a program detab that replaces tabs in the input with the proper number 
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. 
Should n be a variable or a symbolic parameter?   */

#include <stdio.h>

#define NO_TABSTOPS 4
#define MAXLINE 1000

int getlines(char s[], int lim);
void detab(char s[], char o[], int ncolumns);

int main()
{
    int len;
    char lines[MAXLINE];
    char detablines[MAXLINE];

    while((len = getlines(lines, MAXLINE)) > 0){
        detab(lines, detablines, NO_TABSTOPS);
        printf("%s", detablines);
    }

    return 0;
}

int getlines(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void detab(char s[], char detablines[], int ncolumns)
{
    int i, j, k;

    i = j = 0;
    while(s[i] != '\n' && s[i] != '\0'){
        if(s[i] == '\t'){
            for(k = 0; k < ncolumns; k++){
                detablines[j] = ' ';
                ++j;
            }
        }else{
            detablines[j] = s[i];
            ++j;
        }

        ++i;
    }

    detablines[j] = '\n';
    detablines[++j] = '\0';
}
