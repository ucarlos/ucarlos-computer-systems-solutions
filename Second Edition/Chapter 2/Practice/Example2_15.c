#include "common_header.h"
#define EXPRESS(x, y) ((x) == (y))? 1 : 0
int main(void){
    int x = 1, y = 2;
    printf(EXPRESS(x, y)? "TRUE\n" : "FALSE\n");
    return 0;

    
}

