
#include <stdio.h>
#include <stdlib.h>
/*
Given a 2D array of digits,
try to find the occurrence of a given 2D pattern of digits. Return True, False
problem https://www.hackerrank.com/challenges/the-grid-search
code by Alexander Hinds, DarkPurple141
*/

int search(char ** G, int R, int C,
  char ** g, int r, int c) {
    int i,j;
    for (i=R;i<R+r;i++) {
      for (j=C;j<C+c;j++) {
        if (!(G[i][j] == g[i-R][j-C]) ) {
          return 0;
        }
      }
    }
    return 1;
}

// check for subgrid in grid
int gridSearch(char ** G, int R, int C,
  char ** g, int r, int c) {
  int i, j;

  for (i=0; i<R-r+1; i++) {
    j = 0;
    for (j=0;j<C-c+1; j++) {
      if (G[i][j] == g[0][0]) {
        if (search(G,i,j,g,r,c)) {
          return 1;
        }
      }
    }
  }

  return 0;
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

    scanf("%d %d",&r,&c);
    char ** g = malloc(r*sizeof(char*));
    readGrid(g,r,c);

    printf("%s\n",gridSearch(G,R,C,g,r,c) ? "YES" : "NO");

  }

  return 0;
}
