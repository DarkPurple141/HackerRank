#include <stdio.h>
#include <stdlib.h>
/*
input n, k // n is the size of the array being read
print the numer of a[i],a[j] pairs where i < j and
a[i] + a[j] is divisible by k
*/

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

// returns number of pairs
int findPairs(int * a, int size, int k) {
  int i,j, sum;
  int lastPairs, pairs = 0;

  for (i=0;i<size;i++) {
    if (i>0 && a[i] == a[i-1]) {
      pairs += lastPairs;
      continue;
    } else {
      lastPairs = 0;
      for (j=i; j<size; j++) {
        if (a[j] == a[i]) {
          continue;
        }
        sum = a[i] + a[j];
        if (!(sum % k)) {
          lastPairs++;
        }
      }
      pairs += lastPairs;
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

    // sorting values allows us to skip duplicates
    qsort(a, n, sizeof(int), cmpfunc);
    printf("%d\n",findPairs(a,n,k));

    return 0;
}
