#include "../../common_header.h"
/* When given the C code */
void cond(int a, int *p){
    if (p && a > 0)
        *p += a;
}

/*
 * GCC generates the following asembly code for the body of the
 * function:
 * a at %ebp + 8, p at %ebp + 12
 * movl 8(%ebp), %edx -- var1 = a
 * movl 12(%ebp), %eax -- var2 = p
 * testl %eax, %eax -- Test var2
 * je    .L3  -- If equal, jump to L3.
 * testl %edx, %edx -- Test var1
 * jle   .L3  -- If var1 is less than or equal, jump to L3.
 * addl  %edx, (%eax) -- (%eax) = (%eax) + %edx
 *.L3:
 *
 *
 * A) Write a goto version in C that performs the same 
 *    computations and minmics the control flow of the assembly
 *    code, in the style shown in Figure 3.13(b). You might find
 *    it helpful to first annotate the assembly code as we have
 *    done in our examples.
 * 
 * B) Explain why the assembly code contains two conditional 
 *    branches, even though the C code has only one if
 *    statement.
 * -------------------------------------------------------------------
 * These branches are for statements that return false for the 
 * conditional. It's like a dumping ground for expressions that
 * don't pass the test.
 * -------------------------------------------------------------------
 *
 */



void cond_goto_c(int a, int *p){
    if (p == 0)
	goto L3;
    if (a <= 0)
	goto L3;
    *p += a;    
L3:
    return;
       
}
int main(void){
    return 0;
}


