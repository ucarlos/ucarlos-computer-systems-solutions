#include "../common_header.h"

/*
 * Write code for a function with the following prototype:
 */

/*
 * Mask with least significant n bits set to 1.
 * Examples: n = 6 --> 0x2F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */

// int lower_one_mask(int n);

/*
 * Your function should follow the bit-level integer coding rules (page 120).
 * Be careful of the case n = w.
 */

int lower_one_mask(int n){
    // int number = ((1 << (n - 1)) + ((1 << (n - 1)) - 1));
    return ((1 << (n - 1)) + ((1 << (n - 1)) - 1));
}
/* 
 * We have to left shift by (n - 1) in order to prevent the number from
 * setting all bits to 0 again, so we first set every bit before (n - 1) 1 by
 * subtracting 1 from 1 << (n - 1). We then add the (n - 1) bit.
 */
int main(void){
    int mask = 32;
    printf("Masking value of %d:%X\n", mask, lower_one_mask(mask));
    return 0;
}
