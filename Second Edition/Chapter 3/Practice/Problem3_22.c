#include "../../common_header.h"
/*
 * A function, fun_a, has the following overall structure:
 * int fun_a(unsigned x){
 *     int val = 0
 * while(          ){
 *     _________;
 * }
 * return ______;
 *}
 *
 *The GCC C compiler generates the following assembly code:
 *
 * x at %ebp + 8
 * movl     8(%ebp), %edx
 * movl     $0, %eax
 * testl    %edx, %edx
 * je       .L7
 *
 *.L10
 * xorl    %edx, %eax
 * shrl    %edx
 * jne     .L10
 *.L7
 * andl    $1, %eax
 *
 * Reverse engineer the operation of this code and then do the 
 * following:
 *
 * A) Use the assembly-code version to fill the missing parts of 
 *    the C code.
 *
 * B) Describe in English what this function computes.
      The function sets bits to 1 in val and then does this until x equals 0.
      This value is then anded with 1 (as some sort of check for oddity).
 */

int fun_a(unsigned x){
    int val = 0;
    while (x != 0){
	val ^= x;
	x >>= 1;
    }
    return val & 01;
}
