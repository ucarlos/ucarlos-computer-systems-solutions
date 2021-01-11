#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void inplace_swap(int *x, int *y){ //a = a, b = b
    // Remember that a ^ a = 0
    *y = *x ^ *y; // a = a, b = a ^ b
    *x = *x ^ *y; // a = a ^ a ^ b, b = a ^b --> a = 0 ^ b, b = a ^ b --> a = b, b = a ^ b
    *y = *x ^ *y; // a = b, b = a ^ b ^ b --> a  = b, b = a ^ 0 --> a = b, b = a

}

void reverse_array(int *a, int count){
    int first, last;
    for (first = 0, last = count - 1; first < last; first++, last--)
	inplace_swap(&a[first], &a[last]);

}

void print_list(int *list, int length){
    for (int i = 0; i < length; i++)
	printf("%d ", list[i]);

    puts("");
}
int main(void){
    int list_size_bytes = sizeof(int);
    int *list = malloc(list_size_bytes);
    int length = 0, input, index = 0, check;
    puts ("Input an integer. To stop, press any nonnumerical key.");
    while ((check = scanf("%d", &input))){
	    list_size_bytes += sizeof(int);
	    list = realloc(list, list_size_bytes);
	    list[index++] = input;
	    length++;
        
    }

    print_list(list, length);
    //  reverse_array(list, length);
    // print_list(list, length);
    return 0;
}
