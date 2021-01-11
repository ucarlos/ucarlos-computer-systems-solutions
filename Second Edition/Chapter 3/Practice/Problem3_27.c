#include "../../common_header.h"
/*
 * Starting with C code of the form
 * int test(int x, int y){
 *     int val = ____;
 *     if (_______){
 *         if (______)
 *             val = _______;
 *         else
 *             val = _______;
 *     } else if (_______)
 *         val = _______;
 *     return val;
 * }
 *
 * GCC, with the command-line setting '-march=i686', generates
 * the following assembly code:
 *
 *  x at %ebp + 8, y at %ebp + 12
 *  movl   8(%ebp), %ebx = x 
 *  movl   12(%ebp), %ecx = y
 *  testl  %ecx, %ecx 
 *  jle    .L2
 *  movl   %ebx, %edx -- edx = x
 *  subl   %ecx, %edx -- edx = x - y
 *  movl   %ecx, %eax -- eax = y
 *  xorl   %ebx, %eax -- eax = y ^ x
 *  cmpl   %ecx, %ebx -- compare y and x
 *  cmovl  %edx, %eax -- if y < x, %eax = x - y
 *  jmp    .L4
 *.L2:
 *  leal   0(,%ebx, 4), %edx
 *  leal   (%ecx, %ebx), %eax
 *  cmpl   $-2, %ecx
 *  cmovge %edx, %eax
 *.L4
 *
 * Fill in the missing expressions in the C code.
 *
 */

int test(int x, int y){
    int val = x + y;
    if (y > 0){
        if (y < x)
            val = x - y;
        else
            val = x ^ y;
    } else if (-2 >= y)
        val = 4 * x;
    return val;

}
/*
 * This problem is similar to Problem 3.18, except that some of 
 * the conditionals have been implemented by conditional data 
 * transfers. Although it might seem daunting to ﬁt this code
 * into the framework of the original C code, you will ﬁnd 
 * that it follows the translation rules fairly closely.
 *
 */
int test_correct_maybe_not(int x, int y){
    int val = 4 * x;
    if (y > 0){
        if (x < y)
            val = x - y;
        else
            val = x ^ y;
    } else if (y < -2)
        val = x + y;
    return val;
}

int main(void){
    return 0;
}

