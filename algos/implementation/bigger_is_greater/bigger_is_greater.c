#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(char * str, int i, int j) {
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}

void sort(char* str, int len) {
  int i, j;

  for (i=0; i<len; i++) {
    for (j=i+1;j<len; j++) {
      if (str[j] < str[i]) {
        swap(str,i,j);
      }
    }
  }
}

int processString(char * str, int len) {
  // abby -> abyb
  int i, j;
  char curr;
  char * temp;

  for (i=len-1; i>=0; i--) {
    curr = str[i];
    for (j=i-1; j>=0; j--) {
      if (str[j] < curr) {
        swap(str,i,j);

        if (i!=j) {
          temp = &str[j+1];
          sort(temp,len-j-1);
        }
        return 1;
      }
    }
  }
  return 0;
}


int main(void) {
    int t, len;
    scanf("%d",&t);
    char * str = malloc(101);

    while (t) {
      scanf("%s",str);
      len = strlen(str);
      processString(str, len) ? printf("%s\n",str) : printf("no answer\n");

      --t;
    }
    return 0;
}
