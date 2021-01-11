#include "../../common_header.h"

/*
 * Write code for a function with the following prototype:
 */

/* Divide by power of two. Assume 0 <= k < w - 1 */
/* int divide_power2(int x, int k); */

/*
 * The function should compute x / 2^k with correct rounding, and it should
 * follow the bit-level integer coding rules (page 120).
 */

int divide_power2(int x, int k){
    return x >> k;
}

int main(void){
    int number = 5;
    printf("%d\n", divide_power2(number, 2));
    return 0;
}
