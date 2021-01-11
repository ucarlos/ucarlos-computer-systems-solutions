#include "../../common_header.h"

/*
 * A function fun_b has the following overall structure:
 *
 * int fun_b(unsigned x){
 *     int val = 0;
 *     int i;
 *     for ( ; ; ){
 *     
 *     }
 *     return val;
 * }
 *
 * The GCC C compliler generates the following assembly code:
 *
 * x at %ebp + 8
 *
 *   movl    8(%ebp), %ebx -- x 
 *   movl    $0, %eax -- val = 0
 *   movl    $0, %ecx -- i = 0
 * .L13:
 *   leal    (%eax, %eax),   %edx  %edx = 2 * val
 *   movl    %ebx, %eax      val = x;
 *   andl    $1, %eax        val = val & 1
 *   orl     %edx, %eax      val = val | %edx
 *   shrl    %ebx            x >>= 1
 *   addl    $1, %ecx        i++
 *   cmpl    $32, %ecx       Check if i == 32
 *   jne     .L13            if not, continue loop
 *
 * Reverse engineer the operation of this code and then do the
 * following:
 *
 * A. Use the assembly-code version to fill in the missing parts
 *    of the C code.
 * 
 * B. Describe in English what this function computes.
 */
int fun_b(unsigned x){
    int val = 0;
    int i;
    for (i = 0; i <= 32; i++, x >>= 1) {
	//int temp = 2 * val;
	//val = x;
	//val = val & 1;
	//val = val | temp;
	
	val = (x & 01) | (2 * val);
	//x >>= 1;
    }
     
    return val;
}

int main(void){
    return 0;
}

/* B. Describe in English what this function computes.
   This function tests each bit of x for oddity. 2 * val and val are then ORed
   to produce the final value. */
/* This code reverses the bits in x, creating a mirror image. It does this by
shifting the bits of x from left to right, and then ﬁlling these bits in as it
shifts val from right to left. */
