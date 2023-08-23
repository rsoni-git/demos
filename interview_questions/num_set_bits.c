/*
  @Func: Count the number of set bits in the binary representation of an integer
*/


#include <stdio.h>

int main ( void ) {
  int iNumber = 0, iSetBits = 0;
  
  printf("Enter an integer: ");
  scanf("%d", &iNumber);

  while ( iNumber > 0 ) {
    if ( iNumber & 1 )
      iSetBits ++;

    iNumber = iNumber >> 1; 
  }

  printf("Number of set bits: %d\n", iSetBits);
}

