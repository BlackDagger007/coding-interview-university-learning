#include <stdio.h>

/*  a program to print a histogram of the lengths of words in its input. It is 
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.  */

int main()
{
    int nwords[11]; // Assumed words are not more than 10 letters
    int c, i, j, letters;

    for(i = 0; i <= 10; ++i)
        nwords[i] = 0;
    
    i = letters = 0;
    while((c = getchar()) != EOF){
        if(c != ' ' && c != '\n' && c != '\t')
            ++letters;
        else if(letters <= 10){
            ++nwords[letters];
            letters = 0;
        }
    }
    ++nwords[letters];


    for(i = 1; i <= 10; ++i){
        printf("\n%2d | ", i);
        j = 0;
        for(j = 0; j < nwords[i]; ++j)
            printf("*");
    }
}