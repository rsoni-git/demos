/*
  @Func: Perform a syscall
*/

#include <stdio.h>

int main ( void ) {
  unsigned long ulSyscallNumber = 1; // Syscall number for exit
  unsigned long ulExitStatus = 50;

  asm(
    "movl %0, %%eax\n"
    "movl %1, %%ebx\n"
    "int $0x80"
    :
    : "m" (ulSyscallNumber), "m" (ulExitStatus)
    : "eax", "ebx"
  );

  return 0;
}