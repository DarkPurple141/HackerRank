
#include <stdio.h>
#include <stdlib.h>
/*
Given an integer, n , traverse its digits (1,2,...,len(n))
and determine how many digits evenly divide n
(i.e.: count the number of times n divided by each digit i has a remainder of 0).
Print the number of evenly divisible digits.
problem https://www.hackerrank.com/challenges/find-digits
code by Alexander Hinds, DarkPurple141
*/

// returns number of divides
int findDivides(int n) {
  int divides, temp;
  int original = n;

  divides = 0;

  while (n > 0) {
    temp = n%10;
    if (temp && !(original%temp)) {
      divides++;
    }
    n /= 10;
  }

  return divides;
}

int main(void) {
    int n, i;
    int t;

    // read in num tests 't'
    scanf("%d",&t);

    // read in new 'n'
    for(i = 0; i < t; i++){
       scanf("%d",&n);
       printf("%d\n",findDivides(n));
    }

    return 0;
}
