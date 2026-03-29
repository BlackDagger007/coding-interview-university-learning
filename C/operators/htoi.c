/* Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F. */

#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main()
{
    printf("Ox1F to int is %d\n", htoi("0x1F"));
    printf("FF to int is %d\n", htoi("FF"));
    printf("0Xabc to int is %d\n", htoi("0Xabc"));
}

int htoi(char s[])
{
    int n, i;
    n = i = 0;

    if(s[i] == '0'){
        ++i;
        if(s[i] == 'x' || s[i] == 'X'){
            ++i;
        }
    }

    for(;s[i] != '\0'; ++i){
        int digits;

        if(isdigit(s[i])){
            digits = s[i] - '0';
        }else if(s[i] >= 'a' && s[i] <= 'f'){
            digits = s[i] - 'a' + 10;
        }else if(s[i] >= 'A' && s[i] <= 'F'){
            digits = s[i] - 'A' + 10;
        }else{
            // Stop if a non-hex character
            break;
        }

        n = 16 * n + digits;
    }

    return n;
}