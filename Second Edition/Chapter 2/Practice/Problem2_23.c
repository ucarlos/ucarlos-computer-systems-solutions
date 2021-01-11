#include "../common_header.h"

int fun1(unsigned word){
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word){
    return ((int) word << 24) >> 24;
}
   
int main(void){
    printf("Function1: %d\n", fun1(0x00000076));
    printf("Function2: %d\n", fun2(0x00000076));
    printf("Function1: %d\n", fun1(0x87654321));
    printf("Function2: %d\n", fun2(0x87654321));

    printf("Function1: %d\n", fun1(0xEDCBA987));
    printf("Function2: %d\n", fun2(0xedcba987));

}
