/*
  @Func: Check if a given number is binary
  @Notes:
    1. Not very good when long strings are passed in argv[]
    2. There will problems with signedness of the number due to the use of atoi()
*/

#include <stdio.h>
#include <stdlib.h>

int main ( int iArgc, char** ppcArgv ) {
  int iNumber = 0, iDigit = 0;

  if ( iArgc != 2 ) {
    printf("Error: Need a number as parameter to continue\n");
    return -1;
  }

  iNumber = atoi(ppcArgv[1]);

  printf("Number: %d\n", iNumber);

  while ( iNumber > 0 ) {
    iDigit = iNumber % 10;
    if ( iDigit == 0 || iDigit == 1 ) {
      iNumber /= 10;
      continue;
    } else {
      printf("The number representation IS NOT a binary number\n");
      return 0;
    }
  }

  printf("The number representation IS a binary number\n");
  return 0;
}