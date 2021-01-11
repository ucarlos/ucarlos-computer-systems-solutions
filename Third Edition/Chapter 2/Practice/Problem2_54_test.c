#include "../common_header.h"
#include <limits.h>
int main(void){
	int int_val = INT_MAX - 1;
	float float_val = (double) int_val;
	int int_val2 = (int) float_val;

	printf("Initial Value: %d\nCasted to Float: %.3f\n", int_val, float_val);
	printf("Casted back to int: %d\n", int_val2);

	return 0;
}
