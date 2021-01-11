#include "common_header.h"
void inplace_swap(int *x, int *y);
void reverse_array(int a[], int count);
void print_array(const int *a, int count);
void problem_2_12(void);
void problem_2_13_bis(int x, int m);
void problem_2_13_bic(int x, int m);

int main(void){
    //int array[] = {1, 2, 3, 4, 5};
//    print_array(array, sizeof(array)/sizeof(array[0]));
// reverse_array(array, sizeof(array)/sizeof(array[0]));
    //  print_array(array, sizeof(array)/sizeof(array[0]));
    problem_2_12();

    return 0;
}
void inplace_swap(int *x, int *y){
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}
void reverse_array(int a[], int count){
    int first, last;
    //first <= last will cause the middle value in an odd-numbered array
    //to display 0 (Beacause num XOR num = 0). Replace that with
    //first < last.
    for (first = 0, last = count - 1; first < last; first++, last--)
	inplace_swap(&a[first], &a[last]);
}

void print_array(const int *a, int count){
    for (int i = 0; i < count; i++)
	printf("%d ", a[i]);
    printf("\n");
}

void problem_2_12(void){
    //Write C expressions, in terms of variable x, for the following values. Your code should work for any word size w >= 8. For reference, we show the result of evaluating the expressions for x=0x87654321, with w = 32.
    // A) The least significant byte of x, with all other bits set to 0.
    //[0x00000021]
    int number = 0x87654321;
    int a = number & 0xFF;
    //B) All but the least signigicant byte of x complemented, with the least signigicant byte left unchanged.[0x789ABC21]
    int b = number ^ ~0xFF;

    //C) The least signigicant byte set to all 1s, and all other bytes of x left unchanged.
    //[0x876543FF]
    int c = number | 0xFF;

    printf("Number: %x\n%x\n%x\n%x\n", number, a, b, c);

}
void problem_2_13_bis(int x, int m){
}

void problem_2_13_bic(int x, int y){
}
