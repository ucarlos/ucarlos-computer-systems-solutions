#include "../common_header.h"

void copy_int(int val, void *buf, int maxbytes){
    if ((maxbytes - (int)sizeof(val)) >= 0)
	printf("YES, maxbytes is %d and sizeof(val) is %ld", maxbytes, sizeof(val));
    
}

int main(void){
   int *buffer = calloc(10, sizeof(int));
   copy_int(100, buffer, 1);
}
