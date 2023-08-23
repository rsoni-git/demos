/*
  @Func: Prints the XOR truth table
*/

#include <stdio.h>

int main ( void ) {
  printf("A  B  XOR(A^B)\n");
  printf("--------------\n");
  printf("0  0    %d\n", (0^0));
  printf("0  1    %d\n", (0^1));
  printf("1  0    %d\n", (1^0));
  printf("1  1    %d\n", (1^1));

  printf("\nSame as OR, except outputs 0 when BOTH bits are ON\n");
}