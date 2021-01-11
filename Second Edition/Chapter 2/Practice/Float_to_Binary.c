#include "../common_header.h"
#include <math.h>
int main(void){
    double value = 1492.25;
    int exponent = INT_MAX;
    double fraction = frexp(value, &exponent);
    printf("Normal value:%f\tNormalized Fraction:%f\tExponent:%d\n",value,
	   fraction, exponent);
    return 0;

}
