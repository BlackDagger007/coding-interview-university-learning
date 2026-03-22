#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getlines(char s[], int lim);
int main()
{
    int len;
    int year;
    char lines[MAXLINE];


    while((len = getlines(lines, MAXLINE)) > 0){
        year = atoi(lines);

        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            printf("%d is a leap year!\n", year);
        }else{
            printf("%d is not a leap year :(\n", year);
        }
    }

    return 0;
}

int getlines(char s[], int lim){
    int c, i;

    i = 0;
    while(i < lim - 1 && (c = getchar()) != EOF && c != '\n'){
        s[i] = c;
        ++i;
    }


    s[i] = '\0';
    
    return i;
}

