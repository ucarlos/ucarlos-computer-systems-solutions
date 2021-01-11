#include "../../common_header.h"

/*
 * Write a function with the following prototype:
 * int tsub_ok(int x, int y);
 *
 * This function should return 1 if the computation x - y
 * does not overflow.
 */

int tsub_ok(int x, int y){
    //Cases, x is neg, int is pos, POS overflow
    //x is pos, y is neg, NEG overflow

    int subtr = x + (-y);
    int pos_overflow = (x > 0) && (y <= 0) && (subtr < x);
    int neg_overflow = (x < 0) && (y >= 0) && (subtr > x);

    return !(pos_overflow || neg_overflow);
}

int main(void){
    int x,  y;
    printf("Enter two numbers to evaulate:");
    scanf("%d %d", &x, &y);
    
    printf("Numbers:%d %d\tResult:%d\n", x, y, tsub_ok(x, y));

    return 0;    
}
//-2147483648
