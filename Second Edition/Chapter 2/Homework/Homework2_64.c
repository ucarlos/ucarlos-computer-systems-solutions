#include "../common_header.h"

/*
 * Write code to implement the following function:
 * //Return 1 when any odd bit of x equals 1; 0 otherwise
 * //Assume w = 32.
 * int any_odd_one(unsigned int x);
 *
 * Your function should folllow the bit-level integer coding rules (page 120),
 * except that you may assume that data type int has w = 32 bits.
 */

int any_odd_one(unsigned int x){
    return ((x & 0xAAAAAAAA) != 0);
}

int main(void){
    printf("%d\n", any_odd_one(15));
    return 0;
}
