#include "common_header.h"
int tadd_ok(int x, int y){
    int sum = x + y;
    int pos_overflow = (x >= 0) && (y >= 0) && sum < x;
    int neg_overflow = (x < 0) && (y < 0) && sum > x;

    return !(pos_overflow || neg_overflow);

    
}

int main(void){
    printf("%d\n", tadd_ok(1, INT_MAX));
    return 0;
}
