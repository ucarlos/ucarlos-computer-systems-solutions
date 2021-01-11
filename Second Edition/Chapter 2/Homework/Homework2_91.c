#include "../../common_header.h"
/*
 * Bit-level floating-point coding rules, implement the 
 * function with the following prototype:
 *
 * // Compute -f. If f is NaN, then return f.
 * float_bits float_negate(float_bits f);
 *
 * For floating-point number f, this function computes -f.
 * If f is NaN, your function should simply return f.
 * 
 * Test your function by evaluting it for all 2^32 values of
 * argument f and comparing the result to what would be 
 * obtained using your machine's floating-point operations.
 *
 */

typedef unsigned float_bits;

float_bits float_negate(float_bits f){
    //If Special value
    if (((f >> 23) & (0xFF))){
	// Check least 23 bits for ones. If so, f is NaN and return f
	if ((f) & (0x07FFFFF)) return f;
    }
    return ~(f) + 1;
}

float_bits float_negate_slow(float_bits f){
    //If Special value
    float_bits temp = f;
    if (((f >> 23) & (0xFF))){
        for (int i = 0; i < 23; i++, temp >>= 1)
	    if ((temp & 01)) return f;
    }
    //Otherwise
    return ~(f) + 1;
}



int main(void){
    FILE *fp;
    if ((fp = fopen("Homework2_91_Output.txt", "w")) == NULL){
        fprintf(stderr, "Cannot open file. Aborting.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "\t    Number|\t     Float|\n");
    for (unsigned i = (1u << 31) - 2000; i < (1u << 31); i++){
        fprintf(fp, "\t%10d|\t%10d\n", i, float_negate(i));
    }
    fclose(fp);

    return 0;
}
