#include "../../common_header.h"
typedef struct ELE *tree_ptr;

struct ELE{
    long val;
    tree_ptr left;
    tree_ptr right;
};

/*
Using the same tree data structure we saw in Problem 3.69, and a function with
the prototype
long traverse(tree_ptr tp);
gcc generates the following x86-64 code:
1 traverse:
		tp in %rdi
2  movq    %rbx, -24(%rsp)              -- (%rsp - 24) = %rbx
3  movq    %rbp, -16(%rsp)		-- (%rsp - 16) = %rbp
4  movq    %r12, -8(%rsp)		-- (%rsp - 8)  = %rsp
5  subq    $24, %rsp			Allocate 24 bytes for stack
6  movq    %rdi, %rbp			-- %rbp = tp
7  movabsq $-9223372036854775808, %rax	-- %rax = -8000000000000000 
8  testq   %rdi, %rdi		  	Test %rdi with %rdi
9  je 	   .L9	 			If %rdi == 0, go to .L9
10 movq    (%rdi), %rbx			-- %rbx = *tp
11 movq    8(%rdi), %rdi		-- %rdi = tp.left
12 call    traverse 			-- call traverse
13 movq    %rax, %r12			-- %r12 = %rax
14 movq    16(%rbp), %rdi		-- %rdi = tp.right
15 call    traverse  			-- call traverse
16 cmpq    %rax, %r12			-- compare %rax and %r12
17 cmovge  %r12, %rax			-- if %rax >= %r12, %rax = %r12
18 cmpq    %rbx, %rax			-- compare %rbx and %rax
19 cmovl   %rbx, %rax			-- if %rbx < %rax, %rax = %rbx
20 .L9:	   	 
21 movq    (%rsp), %rbx			--%rbx = (%rsp)
22 movq    8(%rsp), %rbp		-- %rbp = (%rsp + 8)
23 movq    16(%rsp), %r12		-- %r12 = (%rsp + 16)
24 addq    $24, %rsp 			-- Deallocate 24 bytes
25 ret	   				-- return

A. Generate a C version of the function.


B. Explain in English what this function computes.
The function traverses through a binary tree's left and right leaves. If there
is no node, it returns a hexadecimal constant which is compared between 
the children of the node. This is stored in result, and then a another comparsion
between result and the value of ELE.val will determine what gets returned. 

*/

long traverse(tree_ptr tp){
    if (tp != NULL){
	long result = traverse(tp->right);
	long temp = traverse(tp->left);
	result = (result >= temp)? temp : result;
	result = (tp->val < result)? tp->val : result;
	return result;       	       
    }
    return -0x8000000000000000;
}
