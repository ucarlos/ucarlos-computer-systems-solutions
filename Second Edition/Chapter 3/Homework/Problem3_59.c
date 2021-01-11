#include "../../common_header.h"
/*
This problem will give you a chance to reverse engineer a switch statement from
machine code. In the following procedure, the body of the switch statement has
been removed:

int switch_prob(int x, int n){
    int result = x;
    switch(n){
        // Fill in code here
    }
    return result;
}

Figure 3.44 shows the disassembled machine code for the procedure. We can see in
lines 4 and 5 that parameters x and n are loaded into registers %eax and %edx,
respectively.

The jump table resides in a different area of memory. We can see from the 
indirect jump on line 9 that the jump table begins at address 0x80485d0. Using
the GDB debugger, we can examine the six 4-byte words of memory comprising the 
jump table with the command x/6 0x80485d0. GDB prints the following:

(gdb) x/6w 0x80485d0
0x80485d0: 0x08048438 0x08048448 0x08048438 0x0804843d
0x80485e0: 0x08048442 0x08048445

Fill in the body of the switch statement with C code that will have the same
behavior as the machine code.
x in %eax, n in %edx
1  08048420 <switch_prob>:
2  8048420: 55				push %ebp
3  8048421: 89 e5  			mov  %esp,%ebp 
4  8048423: 8b 45 08 			mov  0x8(%ebp),%eax                -- %eax = x
5  8048426: 8b 55 0c 			mov  0xc(%ebp),%edx                -- %edx = n
6  8048429: 83 ea 32 			sub  $0x32,%edx                    -- %edx = n - 0x32
7  804842c: 83 fa 05 			cmp  $0x5,%edx                     -- compare 0x5 with %edx
8  804842f: 77 17 			ja   8048448 <switch_prob+0x28>    -- jump if %edx > $0x5 OR $0x5 < %edx
9  8048431: ff 24 95 d0 85 04 08 	jmp  *0x80485d0(,%edx,4)           -- jump to *(0x8045d0 + 4 * n)
10 8048438: c1 e0 02   	     		shl  $0x2,%eax                     -- %eax = x << 0x2
11 804843b: eb 0e 			jmp  804844b <switch_prob+0x2b>    -- jump to 804844b
12 804843d: c1 f8 02 			sar  $0x2,%eax                     -- %eax = x >> 0x2
13 8048440: eb 09 			jmp  804844b <switch_prob+0x2b>    -- jump to 804844b
14 8048442: 8d 04 40 			leal (%eax,%eax,2),%eax            -- %eax = x + 2x = 3x
15 8048445: 0f af c0 			imul %eax,%eax                     -- %eax = (3x) * (3x)
16 8048448: 83 c0 0a 			add  $0xa,%eax                     -- %eax = (3x) * (3x) + 0xa
17 804844b: 5d 	  			pop  %ebp                          -- pop %ebp from stack
18 804844c: c3 				ret                                -- return

Figure 3.44 Disassembled code for Problem 3.59.   
*/

int switch_prob(int x, int n){
    int result = x;
    switch (n){
    case 0x31:
    case 0x33:
	result <<= 0x2;
	break;
    case 0x34:
	result >>= 0x2;
	break;
    case 0x35:
	result = 3 * x;
    case 0x36:
	result *= result;
    default:
	result += 0xa;
	break;
    }

    return result;
}

int main(void){
    return 0;
}
