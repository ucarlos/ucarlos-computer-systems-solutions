#include "../common_header.h"
int tmult_ok(int x, int y);
int main(int argc, char *argv[]){
	if (argc != 3){
		printf("Usage: ./Problem2_35 [Number 1] [Number 2]\n");
		exit(EXIT_SUCCESS);
	}
	
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	printf("%d\n%d\n", num1, num2);
	printf("Can be Multiplied without Overflow? ");
	printf((tmult_ok(num1, num2))? "Yes.\n" : "No.\n");
	
	return 0;
	
}
// Determine whether arguments can be multiplied without overflow.
int tmult_ok(int x, int y){
	int result = x * y;
	// Either x is zero, or dividing p by x gives y:
	return ((!x) || (result / x) == y);
}
