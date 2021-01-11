#include "../../common_header.h"
/*
 * Following the bit-level floating-point coding rules, implement the function
 * with the following prototype:
 * // Compute |f|. If f is NaN, then return f.
 * float_bits float_absval(float_bits f);
 *
 * For floating-point number f, this function computes |f|. If f is NaN, your 
 * function should simply return f.
 * 
 * Test your function by evaluating it for all 2^32 values of argument f and 
 * comparing the result to what would be obtained using your machine's 
 * floating-point operations.
 */

typedef unsigned int float_bits;

float_bits float_absval(float_bits f){
    /* 
     * Check f for NaN by testing if f is a special case
     * and if the least 23 bits contain a one
     */
    if (((f >> 23) & 0xFF) && ((f) & 0x7FFFFF))
	return f;
    /*
     * Check most significant bit
     * if 1, then abs = -(-x). else abs = x.
     */
    return ((f >> 31) & 01) ? (~(f) + 1) : (f);
    
}

int main(void){

    return 0;
}
