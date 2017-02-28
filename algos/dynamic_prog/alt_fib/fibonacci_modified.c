#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// find the nth term of the modified fibonacci sequence where
// f(n+2) = f(n) + f(n+1)^2
// input is three ints. origin inputs and term n, whcih we need to derive

unsigned long long int fib (unsigned long long int i, unsigned long long int j) {
    return i + j*j;
}

int main(void) {

    int it = 1;
    unsigned long long int i, j, n, temp;
    scanf("%llu %llu %llu",&i,&j,&n);

    while (it < n-1) {
        temp = fib(i,j);
        i = j;
        j = temp;

        it++;
    }
    printf("%llu\n",j);

    return 0;
}
