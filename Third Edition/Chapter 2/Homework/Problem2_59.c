#include "../common_header.h"
#define EXPRESSION_MASK_1 (0xffffff00)
#define EXPRESSION_MASK_2 (0x000000ff)
/*
 * Write a C expression that will yield a word consisting of the least significant 
 * byte of x and the remaining bytes of y. For operands x = 0x89ABCDEF and 
 * y = 0x76543210, this would give 0x765432EF.
 *
 */
int main(void){
	int x = 0x89abcdef;
	int y = 0x76543210;
	int mask = (y & EXPRESSION_MASK_1) | (x & EXPRESSION_MASK_2);
	printf("Initial x value: 0x%x\n", x);
	printf("Initial y value: 0x%x\n", y);
	printf("Final Result: 0x%x\n", mask);
	return 0;

}
