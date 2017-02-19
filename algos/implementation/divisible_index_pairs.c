
#include <stdio.h>
#include <stdlib.h>
/*
input n, k // n is the size of the array being read
print the numer of i,j pairs where i < j and aI + aJ is divisible by k
*/

// returns number of pairs
int findPairs(int * a, int size, int k) {
  int i,j, sum;
  int pairs = 0;

  for (i=0;i<size;i++) {
    for (j=i+1; j<size; j++) {
      sum = a[i] + a[j];
      if (!(sum % k)) {
        pairs++;
      }
    }
  }

  return pairs;
}

int main(void) {
    int n, i;
    int k;

    // read in array
    scanf("%d %d",&n,&k);

    // dynamically assign array to size n
    int *a = malloc(sizeof(int) * n);

    // read in values into array
    for(i = 0; i < n; i++){
       scanf("%d",&a[i]);
    }

    printf("%d\n",findPairs(a,n,k));

    return 0;
}
