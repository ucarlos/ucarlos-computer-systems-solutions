#include "../common_header.h"
unsigned int function(unsigned int x, unsigned int y){
    return ((y >> 4) | (unsigned char)(x | (1 << 8)));
}
int main(void){
    printf("%x\n", function(0x89ABCDEF, 0x76543210));
    return 0;
}

z
