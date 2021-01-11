/*
 * Write a function with the following prototype:

 // Determine whether arguments can be added without overflow:
 int uadd_ok(unsigned int x, unsigned int y);

 * This function should return 1 if arguments x and y can be added without
 * causing overflow.
 *
 */


#include "../../common_header.h"
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int uadd_ok(unsigned int x, unsigned int y);

int main(void){
    unsigned int x, y;
    puts("Input two numbers for overflow check:");
    scanf("%u %u", &x, &y);
    int result = uadd_ok(x, y);
    printf((!result)? "An Overflow ocurred during the sum of %u and %u.\n"
	   : "No overflow occurred during the sum of %u and %ud.\n"
	   , x, y);

    return 0;
}

int uadd_ok(unsigned int x, unsigned int y){ // Check for unsigned int overflow
    // MAX(x, y) is used to determine largest operand, for overflow check. 
    unsigned int sum = x + y;
    
    return (sum < MAX(x, y)) ? 0 : 1;

}
