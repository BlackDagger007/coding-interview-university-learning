/* Write a function reverse(s) that reverses the character string s. Use it to 
write a program that reverses its input a line at a time.  */

#include <stdio.h>

#define MAXCHAR 100

void reverse(char s[], int len, char temp[]);
int getlines(char s[], int lim);

int main()
{
    int len;
    char line[MAXCHAR];
    char temp[MAXCHAR];

    while((len = getlines(line, MAXCHAR)) > 0){
        reverse(line, len, temp);
        printf("%s", temp);
    }
}

int getlines(char s[], int lim){
    int c, i;

    i = 0;
    while(i < lim -1 && (c = getchar()) != EOF && c != '\n'){
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

void reverse(char s[],int len, char temp[]){
    int i, j;
    
    j = 0;
    for(i = len - 2; i >= 0; --i){
        temp[j] = s[i];
        ++j;
    }

    temp[j] = '\n';
    temp[++j] = '\0';
}