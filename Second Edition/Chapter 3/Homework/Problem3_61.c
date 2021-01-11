//#include "../../common_header.h"
#include <stdio.h>
/*
The code generated by the C compiler for var_prod_ele (Figure 3.29) cannot fit
all of the values it uses in the loop in registers, and so it must retrieve the
value of n from memory on each iteration. Write C code for this function that
incorporates optimizations similar to those performed by gcc, but such that
the compiled code does not spill any loop values into memory.

Recall that the processor only has six registers available to hold temporary
data, since registers %ebp and %esp cannot be used for this purpose. One of 
these registers must be used to hold the result of the multiply instruction. 
Hence, you must reduce the number of values in the loop 
from six (result, Arow, Bcol, j, n, and 4*n) to five.

You will need to find a strategy that works for your particular compiler. Keep
trying different strategies until you find one that works.
*/


/* Since my compiler is x86-64, I can make the use of the registers %rdi, %rsi,
   %rdx, %rcx, %r8d, and %r9d. 
*/

int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k){
    int j;
    int result = 0;

    for (j = 0; j < n; j++)
	result += A[i][j] * B[j][k];

    return result;
}

int main(void){
    return 0;
}
