#include <stdio.h>

/* counts no. of digits, nwhites and nothers*/

int main()
{
    int ndigits[10];
    int c, i, nwhites, nothers;

    nwhites = nothers = 0;

    for(i = 0; i < 10; ++i){
        ndigits[i] = 0;
    }

    while((c = getchar()) != EOF){
        if(c >= '0' && c <= '9'){
            ++ndigits[c - '0'];
        }else if(c == ' ' || c == '\n' || c == '\t'){
            ++nwhites;
        }else{
            ++nothers;
        }
    }

    printf("\nNo. of digits:");
    for(i = 0; i < 10; ++i){
        printf(" %d", ndigits[i]);
    }
    printf("\nNo. of whites: %d\nNo. of others: %d\n", nwhites, nothers);
}
