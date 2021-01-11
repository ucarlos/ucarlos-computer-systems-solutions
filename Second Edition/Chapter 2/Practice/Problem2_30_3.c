#include "../../common_header.h"
/*
 * Write a function with the following prototype:
 // Determine whether arguments can be added without overflow
 int tadd_ok(int x, int y);
 *
 * This function should return 1 if arguments x and y can be added without causing 
 * overflow.
 */

int tadd_ok(int x, int y);
int main(void){
    int val1, val2;
    puts ("Enter two integers to determine if they can be added without overflow.");
    scanf("%d %d", &val1, &val2);
    int result = tadd_ok(val1, val2);
    printf((!result)? "%d and %d cause an integer overflow.\n"
	   : "%d and %d do not cause an integer overflow.\n",
	   val1, val2);
    
    return 0;
}

int tadd_ok(int x, int y){
    int sum = x + y;
    int pos_overflow = ((x > 0) && (y > 0)) && (sum <= 0);
    int neg_overflow = ((x < 0) && (y < 0)) && (sum >= 0);

    return (pos_overflow || neg_overflow) ? 0 : 1;
    //return !(pos_overflow || neg_overflow); // Pretty much the same.
}
