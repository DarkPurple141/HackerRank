// given a string of characters return the index of the single character to be
// removed that allows the string to become a palindrome
// -- if the string is already a palindrome, return -1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_index (char * array, int len);

int main(void) {
    int t, i, len;
    char * s = malloc(100005);
    scanf("%d",&t);

    for (i=0; i<t; i++) {
      scanf("%s",s);
      len = strlen(s);
      printf("%d\n",find_index(s,len));
    }

    return 0;
}

int find_index (char * array, int len) {
  int returnVal = -1;
  int i, j;

  for (i = 0; i<len/2+1; i++) {
    j = len-1 - i;
    if (array[i] != array[j]) {
      // two checks behind j and in front of i. Need to double check to
      // ensure that we've not mistakenly identified a string where a[j-1] == a[i], but
      // a[i] is the aberration.
      returnVal = (array[j-1] == array[i] ? j : i);

      if (returnVal == j) {
        if (array[i+1] == array[j]) {
          returnVal = i;
        }
      }

      return returnVal;
    }
  }
  return returnVal;

}
