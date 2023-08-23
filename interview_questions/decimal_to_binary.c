/*
  @Func: Convert an integer to its binary representation
*/


#include <stdio.h>

int main ( void ) {
  int iNumber = 0, iIndex = 0;
  int aiBinary[8 * sizeof(int)] = {0};

  printf("Write a number to convert to binary: ");
  scanf("%d", &iNumber);

  while ( iNumber > 0 ) {
    aiBinary[iIndex++] = iNumber % 2;
    iNumber /= 2;
  }

  printf("Binary representation: ");

  for ( int iIter = iIndex; iIter >= 0; iIter-- ) {
    printf("%d", aiBinary[iIter]);
  }

  printf("\n");
  return 0;
}

