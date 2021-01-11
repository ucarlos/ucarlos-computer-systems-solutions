#include "../../common_header.h"
/*
 * In the following varient of the function of Figure 3.8(a), the expressions 
 * have been replaced by blanks:
 * 
 * int artith(int x, int y, int z){
 *     int t1 = __________;
 *     int t2 = __________;
 *     int t3 = __________;
 *     int t4 = __________;
 *     return t4;
 * }
 *
 * The portion of the generated assembly code implementing these expressions is
 * as follows:
 *
 * x at %ebp + 8, y at %epb + 12, z at %ebp + 16
 *
 * mov1  12(%ebp), %eax
 * xorl  8(%ebp), %eax
 * sarl  $3, %eax
 * notl  %eax
 * subl  16(%ebp), %eax
 *
 * Based on this assembly code, fill in the missing portions of the C code.
 */

int arith(int x, int y, int z){
    int t1 = y;
    int t2 = x ^ t1;
    int t3 = ~(t2 >> 3);
    int t4 = t3 - z;
    return t4;
}
int arith_correct(int x, int y, int z){
    int t1 = x ^ y;
    int t2 = t1 >> 3;
    int t3 = ~t2;
    int t4 = t3 - z;
    return t4;
}

           
int main(void){

    return 0;
}
