#include "../common_header.h"
/*
 * Write a procedure is_little_endian that will return 1 when compiled and run 
 * on a little-endian machine, and will return 0 when compiled and run on a 
 * big endian machine. This program should run on any machine, regardless
 * of its word size.
 */

int is_little_endian(int value){
    unsigned char check = (value | (8 * sizeof(unsigned char)));
    unsigned char *pointer = (unsigned char *)&value;

    return (check == pointer[0]);
}

int main(void){
    int value = 0x12345678;
   
    printf("%d\n", is_little_endian(value));
    return 0;
}
