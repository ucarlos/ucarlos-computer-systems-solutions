#include "../common_header.h"
#define LENGTH(x, y) sizeof((x)) / sizeof((y))
int fun1(unsigned int word){
	return (int) ((word << 24) >> 24);

}

int fun2(unsigned int word){
	return ((int) word << 24) >> 24;
  
}
int main(void){
	unsigned int list[] = {0x00000076, 0x87654321, 0x000000C9,0xEDCBA987};
	printf("w\t\tfun1(w)\t\tfun2(w)\n");
	for (int i = 0; i < LENGTH(list, list[0]); i++)
		printf("%x\t\t%x\t\t%x\n", list[i], fun1(list[i]), fun2(list[i]));
	printf("\nDone.\n");
	return 0;
	
}
