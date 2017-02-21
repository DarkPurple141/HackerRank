
#include <stdio.h>
#include <stdlib.h>
/*
Given a 2D array of digits,
try to find the occurrence of a given 2D pattern of digits. Return True, False
problem https://www.hackerrank.com/challenges/the-grid-search
code by Alexander Hinds, DarkPurple141
*/

// check for subgrid in grid
int gridSearch(char ** G, int R, int C,
  char ** g, int r, int c) {
  int returnVal, i, j;

  for (i=0; i<R; i++) {
    j = 0;
    returnVal = 0;

  }

  return returnVal;
}

void readGrid(char ** G, int r, int c) {
  int i,j;
  char temp;
  scanf("%c",&temp);

  for (i=0; i<r; i++) {
    G[i] = (char*)malloc(c);
    for (j=0; j<c; j++) {
      scanf("%c",&G[i][j]);
    }
    scanf("%c",&temp);
  }
}

void printGrid(char ** G, int r, int c) {
  int i,j;

  for (i=0; i<r; i++) {
    for (j=0; j<c; j++) {
      printf("%c",G[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int t, i;
  // num tests
  scanf("%d",&t);

  for(i = 0; i < t; i++) {
    int R,r; // rows
    int C,c; // cols

    scanf("%d %d",&R,&C);
    char ** G = malloc(R*sizeof(char*));
    readGrid(G,R,C);
    printGrid(G,R,C);

    scanf("%d %d",&r,&c);
    char ** g = malloc(r*sizeof(char*));
    readGrid(g,r,c);

    printf("%s\n",gridSearch(G,R,C,g,r,c) ? "YES" : "NO");

  }

  return 0;
}
