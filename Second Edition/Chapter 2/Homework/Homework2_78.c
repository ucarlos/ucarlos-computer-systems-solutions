#include "../../common_header.h"

/*
 * Write code for a function mul3div4 that, for integer argument
 * x, computes 3 * x / 4, but following the bit-level integer 
 * coding rules (page 120). Your code should replicate the fact
 * that the computation 3 * x can cause overflow.
 */

/* Is the return type a double ? */
int mul3div4(int x){
    //If 
    return ((x << 1) + x) >> 2;
}

int main(void){
    int number;
    printf("Enter a number to test this function:");
    scanf("%d", &number);
    printf("\nNum:%d\tResult(mul3div4):%d\t\nRegular Multiplication:%d\n", number, mul3div4(number), ((number * 3) / 4));
    return 0;
}
//2147483647
