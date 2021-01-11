#include "../../common_header.h"

/* Starting with C code of the form
 * [Ommitted]
 * Gcc generates the following assembly code:
 * x at %ebp + 8, y at %abp + 12
 * movl   8(%ebp), %eax
 * movl   12(%ebp), %edx
 * cmpl   $-3, %eax
 * jge   .L2
 * cmpl   %edx, %eax
 * jle   .L3
 * imull  %edx, %eax
 * jmp   .L4
 * 
 *.L3:
 *   leal    (%edx, %eax), %eax
 *   jmp     .L4
 *.L2:
 *   cmpl    $2, %eax
 *   jg      .L5
 *   xorl    %edx, %eax
 *   jmp     .L4
 *.L5:
 *   subl    %edx, %eax
 *.L4:
 * 
 * Fill in them missing expressions in the C code. To make the code fit into
 * the C code template, you will need to undo some of the reordering of 
 * computations done by GCC.
 *
 */

int test(int x, int y){
    int val = y;
    if (-3 < x){
	if (y < x)
	    val = x + y;
	else
	    val = x * y;
    }
    else if (-3 >= x)
	val = (2 < x)? x - y : x ^ y;
   
    return val;
}

/*
 * This problem requires that you work through a nested branch structure, where
 * you will see how our rule for translating if statements has been applied. 
 * For the most part, the machine code is a straightforward translation of 
 * the C code. The only difference is that the initialization expression
 * (line 2 in the C code) has been moved down (line 15 in the assembly code)
 * so that it only gets computed when it is certain that this will be the
 * returned value.
 *
 */

int test_correct(int x, int y){
    int val = x ^ y;
    if (-3 < x){
	if (y < x)
	    val = x + y;
	else
	    val = x * y;
    }
    else if (-3 >= x)
	val = x - y;
    return val;
}
