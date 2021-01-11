#include "../../common_header.h"
/*
 * A C function arithprob with arguments a, b, c, and d has the following body:
     return a * b + c * d;
  
   It compiles to the following x86-64 code:
a = %rdi, b = %rsi, c = %rdx, d = %rcx
arithprob:
  movslq   %ecx, %rcx -- Sign extend %ecx to %rcx
  imulq    %rdx, %rcx -- %rcx = rdx * %rcx 
  movsbl   %sil, %esi -- move byte to l = %esi = %sil
  imull    %edi, %esi -- %esi = %sil * %edi
  movslq   %esi, %rsi -- 
  leaq     (%rcx, %rsi), %rax
  ret


The arguments and return value are all signed integers of various lengths.
Arguments a, b, c, and d are passed in the appropriate regions of registers %rdi,
%rsi, %rdx, and %rcx, respectively. Based on this assembly code, write a function
prototype decribing the rerturn and argument types for arithprob.

*/
long arithprob(int d, long c, char b, int a);

int main(void){
    return 0;
}
