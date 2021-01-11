#include "common_header.h"
int tadd_ok(int x, int y){
    int sum = x + y;
    int pos_over = (x >= 0) && (y >= 0) && (sum < 0);
    int neg_over = (x < 0) && (y < 0) && (sum >= 0);

    return !(pos_over || neg_over);
}

/*
  Determine whether arguments can be substracted without overflow:
*/
int tsub_ok(int x, int y){
    return tadd_ok(x, -y);
}

int main(void){
    printf("%d\n", tsub_ok(-5, INT_MIN));
    return 0;
}
