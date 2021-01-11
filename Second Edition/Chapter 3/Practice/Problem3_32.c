#include "../../common_header.h"
/*
 * A C function fun has the following code body:
     [pointer -- cant use star symbol]p = d;
     return x - c;
 * The IA32 code implementing this body is as follows:
         movsbl   12(%ebp), %edx -- %edx = %ebp + 12
         movl     16(%ebp), %eax -- %eax = %ebp + 12
         movl     %edx, (%eax)  -- *%eax = %edx
         movswl   8(%ebp), %eax -- %eax = %ebp + 12
         movl     20(%ebp), %edx -- %edx = %ebp + 20
         subl     %eax, %edx -- %edx = %edx - %eax
         movl     %edx, %eax -- %eax = %edx
 *
 * Write a prototype for function fun, showing the types and 
 * ordering of the arugments p, d, x, and c.
 *
 */

int fun(char d, int *p, short c, int x){
    *p = d;
    return x - c;
}
int main(void){
}
/*
 One step in learning to read IA32 code is to become very 
 familiar with the way arguments are passed on the stack. 
 The key to solving this problem is to note that the storage
 of d at p is implemented by the instruction at line 3 of the
 assembly code, from which you work backward to determine the
 types and positions of arguments d and p. Similarly, the
 subtraction is performed at line 6, and from this you can
 work backward to determine the types and positions of
 arguments x and c. The following is the function
 prototype:

 int fun(short c, char d, int *p, int x);

 As this example shows, reverse engineering is like solving
 a puzzle. It’s important to identify the points where there
 is a unique choice, and then work around these points to ﬁll
 in the rest of the details.
*/
