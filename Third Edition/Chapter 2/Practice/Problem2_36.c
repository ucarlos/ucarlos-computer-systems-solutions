#include "../common_header.h"
//If for whatever reason common_header doesn't include this:
//#include <stdint.h>
int32_t tmult_ok(int32_t x, int32_t y);

int main(int argc, char *argv[]){
	if (argc != 3){
		printf("Usage: ./Problem2_36 [Number 1] [Number 2]\n");
		exit(EXIT_FAILURE);
	}
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	printf("Number 1: %d\tNumber 2: %d\n", num1, num2);
	printf("Numbers can be multiplied without Overflow? ");
	printf((tmult_ok(num1, num2)? "Yes.\n" : "No.\n"));

}

int32_t tmult_ok(int32_t x, int32_t y){
	int32_t result = x * y;
	return ((result == (int64_t)(x * y))? 1 : 0);

}
