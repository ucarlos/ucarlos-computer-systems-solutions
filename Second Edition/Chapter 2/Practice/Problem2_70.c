#include "../common_header.h"

//Write code for the function with the following prototype:

/*
 * Return 1 when x can be represented as an n-bit, 2's complement number;
 * 0 otherwise.
 * Assume 1 <= n <= w
 */

//Your function should follow the bit-level integer coding rules (page 120).

/*
 I'm assuming you are working on a 2s complement machine (vice sign-magnitude or some other kind of arithmetic)
and need to avoid loops and conditionals as well. This is clearly some kind of puzzle, so let's not worry
about portability and assume 32-bit ints.

If the value is positive, all bits from n-1 through the highest order bit of the int must be zeros. If the
value is negative, the same bits must be ones. So one approach is to check those bits for the correct value.

This is equivalent to checking whether x >> (~0+n) is all zeros if x is positive and all ones otherwise. 
It "shifts out" the bits that are free to have any value.

We can also construct a mask that's all zeros if x is positive, else ones, with x >> 31.

Finally, we can check equality of any ints a and b using !(a ^ b).

Putting all this together, you'd get:
*/
int fits_bits(int x, int n){
    // return (((x) | ((1 << (n - 1)) - 1)) != 0) ^ ((x) >> (~0 + n));
     return !((x >> 31) ^ (x >> (~0 + n)));
}
int main(void){

    return 0;

}
