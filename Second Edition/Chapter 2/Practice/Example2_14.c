#include "common_header.h"
int example2_15(int x, int y);
#define isEqual(x, y) (!((x) ^ (y)))

int main(void){
    int x = 0x66, y = 0x39;
    printf("x & y = %d\nx && y = %d\nx | y = %d\nx || y = %d", (x & y), (x && y),(x | y), (x || y));
    printf("\n~x | ~y = %d\n!x || !y = %d\nx & !y = %d\nx && ~y = %d\n", (~x | ~y), (!x || !y), (x & !y), (x && ~y));

    puts("Trying Example2_15");
    printf("%d\n", example2_15(1, 1));
    printf("%d\n", example2_15(1, 2));

    
    return 0;
}

int example2_15 (int x, int y){
    //Using only bit-level and logical operations, write an expresssion
    //that is equiv. to x == y.
    return isEqual(x, y); 
}

