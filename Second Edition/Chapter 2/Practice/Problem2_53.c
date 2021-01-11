/* 
 * Fill in the following macro defintions to generate the double-precision
 * values, +INFINITY, -INFINITY, and 0:
 * #define POS_INFINITY
 * #define NEG_INFINITY
 * #define NEG_ZERO
 */

#define POS_INFINITY (1e400)
#define NEG_INFINITY -POS_INFINITY
#define NEG_ZERO (-1.0 / POS_INFINITY)

/* 
 * You cannot use any include files (such as math.h), but you can make use of 
 * the fact that the largest finite number that can be represented with
 * double precision is around 1.8 x 10^308.
 */

#include <stdio.h>
int main(void){
    printf("%ld\n", sizeof(long double));
    return 0;
}

