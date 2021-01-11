#include "common_header.h"

//Include Examples headers here:

void testsignedvalues(void){
    int tx, ty;
    unsigned ux, uy;
    tx = ux; // Cast to signed
    uy = ty; // Cast to unsigned

    printf("%d\n%u", tx, uy);
    
}


int main(void){
    testsignedvalues();

    
}

