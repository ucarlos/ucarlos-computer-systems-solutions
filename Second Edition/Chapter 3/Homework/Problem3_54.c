#include "../../common_header.h"
/*

A function with prototype
int decode2(int x, int y, int z);
is compiled into IA32 assembly code. The body of the code is as follows:

x at %ebp+8, y at %ebp+12, z at %ebp+16
1  movl    12(%ebp), %edx -- %edx = y
2  subl    16(%ebp), %edx -- %edx = y - z
3  movl    %edx, %eax -- %eax = y - z
4  sall    $31, %eax -- %eax = (y - z) << 31
5  sarl    $31, %eax -- %eax = ((y - z) << 31) >> 31
6  imull   8(%ebp), %edx -- %edx = (y - z) * x
7  xorl    %edx, %eax -- %eax = %eax ^ (%rdx)

Parameters x, y, and z are stored at memory locations with offsets 8, 12, and 16
relative to the address in register %ebp. 
The code stores the return value in register %eax.
Write C code for decode2 that will have an effect equivalent to our assembly
code

*/

int decode2(int x, int y , int z){
    int temp1 = y - z;
    int temp2 = temp1 << 31;
    temp2 >>= 31;
    temp1 *= x;
    return temp1 ^ temp2;
}

int decode2_simple(int x, int y, int z){
    return (((y - z) << 31) >> 31) ^ ((y - z) * x);
}

int main(void){
    return 0;
}
