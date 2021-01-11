#include "../../common_header.h"

/*
A function fun_c has the following overall structure:

long fun_c(unsigned long x){
    long val = 0;
    int i;
    for (_______;_____;_____){
        _________;
    }
    _________;
    return ________;
}

The GCC C compiler generates the following assembly code:

1   fun_c:
     x in %rdi
2     movl     $0, %ecx -- %ecx = 0
3     movl     $0, %edx -- %edx = 0 
4     movabsq  $72340172838076673, %rsi -- Move 64-bit val to %rsi
5 .L2:
6     movq     %rdi, %rax   -- %rax = x 
7     andq     %rsi, %rax   -- %rax = x & %rsi
8     addq     %rax, %rcx   -- %rcx = %rcx + %rax
9     shrq     %rdi         --    x = x >>= 1
10    addl     $1, %edx     -- %edx = %edx + 1
11    cmpl     $8, %edx     -- compare 8 and %edx
12    jne      .L2          -- Continue loop if 8 != %edx

13    movq     %rcx, %rax   -- %rax = %rcx
14    sarq     $32, %rax    -- %rax >>= 32
15    addq     %rcx, %rax   -- %rax += %rcx
16    movq     %rax, %rdx   -- %rdx = %rax
17    sarq     $16, %rdx    -- %rdx >>= 16
18    addq     %rax, %rdx   -- %rdx += %rax
19    movq     %rdx, %rax   -- %rax = %rdx
20    sarq     $8, %rax     -- %rax >>= 8
21    addq     %rdx, %rax   -- %rax = %rax + %rdx
22    andl     $255, %rax   -- %eax = %eax & 255
23    ret

Reverse engineer the operation of this code. 
You will find it useful to convert the decimal constant on line 4 to hexadecimal.
A. Use the assembly-code version to fill in the missing parts of the C code.

B. Describe in English what this code computes.

*/
#define CONST 0x101010101010101

long fun_c(unsigned long x){
    long val = 0;
    int i;
    for (i = 0; i != 8; i++){
	val += (x & CONST);
	x >>= 1;	
    }
    val = (val >> 32) + val;
    val = (val >> 16) + val;
    val = (val >> 8) + val;
    return val & 0xFF;
}
