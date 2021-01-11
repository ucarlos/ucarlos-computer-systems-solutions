#include <stdio.h>
void inplace_swap(int *x, int *y);
void inplace_swap(int *x, int *y){ //a = a, b = b
    // Remember that a ^ a = 0
    *y = *x ^ *y; // a = a, b = a ^ b
    *x = *x ^ *y; // a = a ^ a ^ b, b = a ^b --> a = 0 ^ b, b = a ^ b --> a = b, b = a ^ b
    *y = *x ^ *y; // a = b, b = a ^ b ^ b --> a  = b, b = a ^ 0 --> a = b, b = a

}
