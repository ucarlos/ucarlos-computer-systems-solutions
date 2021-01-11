#include "../common_header.h"
// Write a function with the following prototype:
int tadd_ok(int x, int y);
// This function should return 1 if arguments x and y can be added without causing

int main(void){
	
}

int tadd_ok(int x, int y){
	int sum = x + y;
	// Check for Negative overflow:
	int pos_overflow = (x > 0) && (y > 0) && (sum < 0);
	int neg_overflow = (x < 0) && (y < 0) && (sum >= 0);
	
	return !(pos_overflow || neg_overflow);

}
