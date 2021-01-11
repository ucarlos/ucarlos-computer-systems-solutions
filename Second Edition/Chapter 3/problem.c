#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
	int x_1, y_1, z_1;
	int x_2, y_2, z_2;
	puts("Enter Point 1.");
	scanf("%d %d %d", &x_1, &y_1, &z_1);
	puts("Now Enter Point 2.");
	scanf("%d %d %d", &x_2, &y_2, &z_2);

	double result = pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2) + pow((z_2 - z_1), 2);
	result = sqrt(result);
	printf("The result is %.3f\n", result);

	return 0;
}

