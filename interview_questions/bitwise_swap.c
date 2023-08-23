/*
  @Func: Swap numbers using the bitwise operator
*/

#include <stdio.h>

int main ( void ) {
  int iA = 0, iB = 0;
  printf("Enter space seperated values for A and B: ");
  scanf( "%d %d", &iA, &iB );
  printf("\nNumbers: A = %d, B = %d\n", iA, iB);

  iA = iA ^ iB;
  iB = iA ^ iB;
  iA = iA ^ iB;

  printf("Values after swap: A = %d, B = %d\n", iA, iB);

  return 0;
}