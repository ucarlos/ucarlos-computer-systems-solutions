#include "../../common_header.h"



typedef struct ELE *tree_ptr;
struct ELE{
    long val;
    tree_ptr left;
    tree_ptr right;
};

/*
long trace(tree_ptr tp);

The following declaration defines a class of structures for use in constructing
binary trees:
1 typedef struct ELE *tree_ptr;
2
3 struct ELE {
4 	 long val;
5 	 tree_ptr left;
6 	 tree_ptr right;
7 };

For a function with the following prototype:
long trace(tree_ptr tp);
gcc generates the following x86-64 code:
1 trace:
		tp in %rdi
2  movl     $0, %eax     -- %eax = 0
3  testq    %rdi, %rdi	 -- Test tp
4  je 	    .L3	  	 -- if tp == 0, exit
5 .L5:
6  movq     (%rdi), %rax  -- %rax = *(tp)
7  movq     16(%rdi), %rdi -- %rdi = left
8  testq    %rdi, %rdi	   -- Test %rdi with %rdi
9  jne 	    .L5	  	   -- If %rdi != 0, loop
10 .L3:
11 rep
12 ret

A. Generate a C version of the function, using a while loop.

B. Explain in English what this function computes.

*/

long trace(tree_ptr tp){
    while (tp != NULL){
	tp = tp->left;
    }
    return tp->val;
}
