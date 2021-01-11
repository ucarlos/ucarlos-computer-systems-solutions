#include "../common_header.h"
#define FLOAT_BIAS (127)
#define FLOAT_SIZE (32)
void display_float_bits(float value);

int main(void){
	float value;
	puts("Enter a floating-point value:");
	scanf("%f", &value);

}

void display_float_bits(float value){
	char *string = calloc(FLOAT_SIZE, sizeof(char));
	unsigned  sign = (unsigned int)value & 0x80000000;
	unsigned exponent = (unsigned int)value & 0x7f800000;
	unsigned fractional = (unsigned int)value &0x007fffff;
	unsigned bias = exponent - FLOAT_BIAS;
	
}
