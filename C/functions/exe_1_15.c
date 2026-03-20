/* Rewrite the temperature conversion program of Section 1.2
for conversion.  */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahrToCelsius(int);

int main()
{
    int i;
    for(i = LOWER; i <= UPPER; i = i + STEP){
        printf("\n%3d\t%6.1f", i, fahrToCelsius(i));
    }
    return 0;
}

float fahrToCelsius(int fahr){
    return (5.0 / 9.0) * (fahr - 32);
}
