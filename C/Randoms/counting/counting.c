#include <stdio.h>

#define IN 1
#define OUT 0

/* line, word and character Counting */
int main()
{
    int c, ln, wn, cn, state;

    state = OUT;
    ln = wn = cn = 0;

    while((c = getchar()) != EOF){
        ++cn;
        if(c == '\n')
            ++ln;
        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
        }else{
            if(state == OUT)
                ++wn;
            state = IN;
        }
    }

    printf("\nNo. Lines: %d\nNo. Words: %d\nNo. Characters: %d\n",ln, wn, cn);
}


// int main()
// {
//     int c;
//     while((c = getchar()) != EOF){
//         printf("%d", c > '0');
//     }
// }