#include "../common_header.h"

/*
 * Suppose we number the bytes in a w-bit word from 0 (least signigficant)
 * to w / 8 - 1 (most significant). Write code for the following C function,
 * which will return an unsigned value in which byte i of argument x has 
 * been replaced by byte b:
 * unsigned replace_byte (unsigned x, int i, unsigned char b);
 * 
 * Here are some examples showing how the function should work:
 * replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
 * replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
 */

//Works with little endian machines, but 
unsigned int replace_byte (unsigned x, int i, unsigned char b){
    //Check if bytes are order by Little or Big Endian by examining least sig. byte
    unsigned char check = (x | (8 * sizeof(unsigned char)));
    unsigned char *pointer = (unsigned char *)&x;

    if (check == pointer[0]) // If Little Endian
	pointer[i] = b;
    else //Otherwise find byte placement
	pointer[8 * (sizeof(unsigned int)) - (i << 1)] = b;
    return x;
   
}

int main(void){
    int value = 0x12345678;
    printf("%x\n", replace_byte(value, 3, 0xAB));
}

