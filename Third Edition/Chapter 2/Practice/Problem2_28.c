#include "../common_header.h"
int uadd_ok(unsigned int x, unsigned int y);

int main(void){
	unsigned int x, y;
	puts("Enter two Unsigned Integers:");
	scanf("%d %d", &x, &y);
	printf("Can %u and %u be added without overflow? : ", x, y);
	printf(!(uadd_ok(x, y))? "Nope." : "Yes");

	return 0;
}

int uadd_ok(unsigned int x, unsigned int y){
	unsigned sum = x + y;
	return ((sum < x) ? 0 : 1);
}
