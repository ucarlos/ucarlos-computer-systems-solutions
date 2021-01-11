#include "../../common_header.h"
/* For a C function switcher with the general structur */
/* int switcher(int a, int b, int c){
       int answer;
       switch(a){
       case _________: // Case A
          c = ______;
	  // Fall through
       case _________: // Case B
           answer = _______;
	   break;
       case _______: // Case C
       case _______: // Case D
           answer = ______;
	   break;
       case ______: // Case E
           answer = ______;
	   break;
       default:
           answer = ______;
       }
       return answer;
}
*/

/*
 * GCC generates the assembly code and jump table shown below. 
   Fill in the missing parts of the C code. Except for the ordering
   of case lablels C and D, there is only one way to fit the different
   cases into the template.

   a at %epb + 8, b at %ebp + 12, c at %ebp + 16
   movl   8(%ebp), %eax
   cmpl   $7, %eax
   ja     .L2
   jmp    *.L7(, %eax, 4)
  
.L2:                        
   movl   12(%ebp), %eax 
   jmp    .L8
.L5:
   movl   $4, %eax
   jmp    .L8
.L6:
   movl   12(%ebp), %eax
   xorl   $15, %eax
   movl   %eax, 16(%ebp)
.L3:
   movl   16(%ebp), %eax
   addl   $112, %eax
   jmp    .L8
.L4:
   mobl   16(%ebp), %eax
   addl   12(%ebp), %eax
   sall   $2, %eax
.L8:
-----------------------------------------------------------------------------------------
.L7: -- 8 elements
   .long  .L3 -- 0
   .long  .L2 -- 1
   .long  .L4 -- 2
   .long  .L2 -- 3
   .long  .L5 -- 4
   .long  .L6 -- 5
   .long  .L2 -- 6
   .long  .L4 -- 7


*
*/
// a at %ebp + 8, b at %ebp + 12, c at %ebp + 16
int switcher(int a, int b, int c){
    int answer;
    switch(a){
    case 5:
	    c = b ^ 15;

    case 0:
	    answer = c + 112;
	    break;
    case 7:
    case 2:
	    answer = (c + b) << 2;
	    break;
    case 4:
	    answer = 4;
	    break;
    default:
	    answer = b;
    }
    return answer;
}

/*
The key to reverse engineering compiled switch statements is to combine the
information from the assembly code and the jump table to sort out the different
cases. We can see from the ja instruction (line 3) that the code for the default
case has label .L2. We can see that the only other repeated label in the jump 
table is .L4, and so this must be the code for the cases C and D. We can see 
that the code falls through at line 14, and so label .L6 must match case A and 
label .L3 must match case B. That leaves only label .L2 to match case E.

*/
