/*
  @Func: Reverse order digits in an interger
*/

#include <stdio.h>
#include <stdlib.h>

int main ( int iArgc, char** ppcArgv ) {
  int iNumber = 0, iReverse = 0;

  if ( iArgc != 2 ) {
    printf("Error:  Need a number as parameter to continue\n");
    return -1;
  }

  iNumber = atoi(ppcArgv[1]);
  printf("Number (before reverse): %d\n", iNumber);

  while ( iNumber > 0 ) {
    iReverse = iReverse * 10 + (iNumber % 10);
    iNumber = iNumber / 10;
  }

  printf("Number (after reverse): %d\n", iReverse);

  return 0;
}
