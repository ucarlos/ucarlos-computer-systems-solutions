#include "../common_header.h"
#define BITSIZE (sizeof(int) * 8)
void convert(int number, char *string, int slen){
    if (slen != BITSIZE){
	fprintf(stderr, "Cannot convert Integer: String length %d smaller than Bitsize %lud.", slen, BITSIZE);
	exit(EXIT_FAILURE);
    }
    char temp[BITSIZE + 1];
    temp[BITSIZE] = '\0';
    for (int i = BITSIZE - 1; i >= 0; i--, number>>= 1)
	temp[i] = (number & 01) + '0';

    strncpy(string, temp, BITSIZE); 


}
int main(void){
    char *value = malloc(BITSIZE);
    int number = 3510593;
    convert(number, value, BITSIZE);
    printf("%d to Binary is %s\n", number, value);
    free(value);
    return 0;
}
