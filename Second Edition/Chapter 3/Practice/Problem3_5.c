#include "../../common_header.h"

/*
 * You are given the following information. A funcion with
 * prototype
 * void decode(int *xp, int *yp, int *zp);
 * is compiled into assembly code. The body of the code is
 * as follows:
 * // xp at %ebp + 8, yp at %ebp + 12, zp at %ebp + 16
 *
 * movl  8(%ebp), %edi
 * movl 12(%ebp), %edx
 * movl 16(%ebp), %ecx
 * movl  (%edx), %ebx
 * movl  (%ecx), %esi
 * movl  (%edi), %eax
 * movl  %eax, (%edx)
 * movl  %ebx, (%ecx)
 * movl  %esi, (%edi)
 *
 * Parameters xp, yp, and zp are stored at memory locations with
 * offsets 8, 12, and 16, respectively, relative to the address
 * in registers %ebp.
 *
 * Write C code for decode1 that will have an effect equivalent
 * to the assembly code above.
 *
 */

void decode1(int *xp, int *yp, int *zp){
 
    int variable1 = *yp;
    int variable2 = *zp;
    int variable3 = *xp;

    *yp = variable3;
    *zp = variable1;
    *xp = variable2;
}
int main(void){

    return 0;
}
