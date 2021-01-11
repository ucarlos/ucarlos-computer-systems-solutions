//
// Created by ulysses on 5/19/18.
//


/*
 * You are assigned the task of writing code for a function tsub_ok, with arguments
 * x and y, that will return 1 if computing x - y does not cause overflow. Having
 * just written the code for Problem 2.30, you write the following:
 * // Determine whethwer arguments can be subtracted without overflow
 * // WARNING: This code is buggy
 * int tsub_ok(int x, int y){
 *     return tadd_ok(x, -y);
 * }
 *
 * For what values of x and y will this function give incorrect results? Writing
 * a correct version of this function is left as an exercise (Problem 2.74).
 */

#include "../../common_header.h"
int tsub_ok(int x, int y);
int tadd_ok(int x, int y);
int main(void){
    int val1, val2;
    puts("Enter two integers to check for overflow.");
    scanf("%d %d", &val1, &val2);
    int result = tsub_ok(val1, val2);
    printf((!result)? "%d - %d caused an overflow.\n" :
           "%d - %d does not cause an overflow.\n"
           , val1, val2);

    return 0;
}

int tsub_ok(int x, int y){
    return tadd_ok(x, -y);
}

int tadd_ok(int x, int y){
    int sum = x + y;
    int pos_overflow = ((x > 0) && (y > 0)) && (sum <= 0);
    int neg_overflow = ((x < 0) && (y < 0)) && (sum >= 0);

    return (pos_overflow || neg_overflow) ? 0 : 1;
    //return !(pos_overflow || neg_overflow); // Pretty much the same.
}


/*
 * Response:
 * Using INT_MIN as one of the arguments will cause an error in the program. For example,
 * x - (INT_MIN) will cause an overflow.
 */

/*
 * Book Solution:
 * This function will give correct values, except when y is TMin. In this case, we will
 * have -y also equal to TMin, and so the call to function tadd_ok will indicate 
 * overflow when x is negative and no overflow when x is nonnegative. In fact, the 
 * opposite is true: tsub_ok(x, TMin) should yield 0 when x is negative and 1 when it is
 * nonnegative. One lesson to be learned from this exercise is that TMin should be included
 * as one of the cases in any test procdeure for a function.
 */
