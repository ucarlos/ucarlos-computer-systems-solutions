/*
You are given the following information. A function with prototype
	void decode1(long *xp, long *yp, long *zp);

is compiled into assembly code, yielding the following:
	void decode1(long *xp, long *yp, long *zp);

	xp in %rdi, yp in %rsi, zp in %rdx

decode1:
movq	(%rdi), %r8
movq	(%rsi), %rcx
movq	(%rdx), %rax
movq	%r8, (%rsi)
movq	%rcx, (%rdx)
movq	%rax, (%rdi)
ret

Parameters xp, yp, and zp are stored in registers %rdi, %rsi, and %rdx, respec-
tively.


Write C code for decode1 that will have an effect equivalent to the assembly
code shown.
*/

#include "../common_header.h"

void decode1(long *xp, long *yp, long *zp);

int main(void){
	long var1, var2, var3;
	var1 = 15;
	var2 = 20;
	var3 = 25;

	printf("%ld\t%ld\t%ld\n", var1, var2, var3);
	decode1(&var1, &var2, &var3);
	printf("%ld\t%ld\t%ld\n", var1, var2, var3);
	return 0;
	

}

void decode1(long *xp, long *yp, long *zp){
	long var1 = *xp;
	long var2 = *yp;
	long var3 = *zp;

	*yp = var1;
	*zp = var2;
	*xp = var3;
}
 
