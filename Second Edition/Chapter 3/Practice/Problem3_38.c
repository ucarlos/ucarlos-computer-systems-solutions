#include "../../common_header.h"

/*
  The following C code sets the diagonal elements of one of
  our fixed-size arrays to val:
  // Set all diagonal elements to val
  void fix_set_diag(fix_matrix A, int val){
     int i;
     for (i = 0; i < N, i++)
       A[i][i] = val;
  }

When compiled, GCC generates the following assembly code:
   A at %ebp + 8, val at %ebp + 12
   movl     8(%ebp), %ecx   -- %ecx = A
   movl     12(%ebp), %edx  -- %edx = val
   movl     $0, %eax        -- %eax = 0
 .L14:
   movl     %edx, (%ecx, %eax) -- M[A + %eax] = val
   addl     $68, %eax     -- %eax += 68 
   cmpl     $1088, %eax   -- compare 1088 and %eax
   jne      .L14       -- If 1088 != %eax, continue.

Create a C-code program fix_set_diag_opt that uses optimizations
similar to those in the assembly code, in the same style as the
code in Figure 3.28(b). Use expressions involving the parameter
N rather than integer constants, so that your code will work
correctly if N is redefined.

*/
#define N 16
typedef int fix_matrix[N][N];

int fix_set_diag_opt(fix_matrix A, int val){
    int i;
    int *prow = A[0][0], *pcol = A[0][0];
    do{

    }while 
}

int main(void){

    return 0;
}

/*

-----------------------------------------------------------------------
-----------------------------------------------------------------------
This exercise requires that you be able to study 
compiler-generated assembly code to understand what
optimizations have been preformed. In this case, the compiler 
was clever in its optimizations.

Let us first study the following C code, and then see how it is
derived from the assembly code generated for the original 
function.

*/

void fix_set_diag_opt_correct(fix_matrix A, int val){
    int *Abase = &A[0][0];
    int index = 0;
    do{
        Abase[index] = val;
        index += (N + 1);
    }while (index != (N + 1) * N);
}

/*
 This function introduces a variable Abase, of type int *, 
 pointing to the start of array A. This pointer designates a
 sequence of 4-byte integer consisting of elements of A in 
 row-major order. We introduce an integer variable index that
 steps through the diagonal elements of A, with the property 
 that once we reach diagonal element N (index value N(N + 1)),
 we have gone beyond the end. 

 The actutal assembly code follows this general form, but now
 the pointer increments must be scaled by a factor of 4. We 
 lable register %eax as holding a value index4 equal to index in
 our C version, but scaled by a factor of 4. For N = 16, we can
 see that our stopping point for index4 will be 4 * 16(16 + 1)
 = 1088.

-----------------------------------------------------------------------
-----------------------------------------------------------------------
A at %ebp + 8, val at %ebp + 12
  movl    8(%ebp), %ecx  --- Get Abase = &A[0][0]
  movl    12(%ebp), %edx --- Get val
  movl    $0, %eax  --- Set index4 to 0

.L14 -- loop
  movl    %edx, (%ecx, %eax) -- Set Abase[index4/4] to val
  addl    $68, %eax    -- index4 += 4(N + 1)
  cmpl    $1088, %eax  -- Compare index4: 4N(N + 1)
  jne     .L14   -- If !=, goto loop

-----------------------------------------------------------------------
-----------------------------------------------------------------------

*
*/
                                          
