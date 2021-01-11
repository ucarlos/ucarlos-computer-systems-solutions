	.file	"Homework2_92.c"
	.text
	.globl	float_absval
	.type	float_absval, @function
float_absval:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	shrl	$23, %eax
	movzbl	%al, %eax
	testl	%eax, %eax
	je	.L2
	movl	-4(%rbp), %eax
	andl	$8388607, %eax
	testl	%eax, %eax
	je	.L2
	movl	-4(%rbp), %eax
	jmp	.L3
.L2:
	movl	-4(%rbp), %eax
	testl	%eax, %eax
	jns	.L4
	movl	-4(%rbp), %eax
	negl	%eax
	jmp	.L6
.L4:
	movl	-4(%rbp), %eax
.L6:
	nop
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	float_absval, .-float_absval
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
