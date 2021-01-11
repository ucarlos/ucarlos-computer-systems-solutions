#include "../common_header.h"
void inplace_swap(int *a, int *b);
void print_values(int step, int *a, int *b);
/*
 * As an application of the property that a ^ a = 0 for any bit vector a, consider the
 * following program:
 */


int main(void){
    int a = 10, b = 5;
    inplace_swap(&a, &b);
    return 0;
    
}
void inplace_swap(int *a, int *b){
    print_values(0, a, b);
    *b = *a ^ *b;
    print_values(1, a, b);
    *a = *a ^ *b;
    print_values(2, a, b);
    *b = *a ^ *b;
    print_values(3, a, b);

}
void print_values(int step, int *a, int *b){
    printf("Step %d : a = %d\tb = %d\n", step, *a, *b);
}


