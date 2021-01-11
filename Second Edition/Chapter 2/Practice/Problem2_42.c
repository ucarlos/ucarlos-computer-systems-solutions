#include "../common_header.h"
/*
 * Write a function div16 that returns the value x / 16 for any integer
 * Argument x. Your function should not use division, modulus, multiplication,
 * any conditionals(if or ?:), any comparision operators (e.g, <, > or ==), or
 * any loops. You may assume that data type int is 32 bits long and uses a two's
 * complment representation, and that right shifts are preformed arithmetically.
 */

int div16(int x){
    return (x >> 4);
}
int main(void){
    printf("%d\n", div16(-16));
    return 0;
}
