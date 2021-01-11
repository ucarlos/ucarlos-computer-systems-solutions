#include "common_header.h"
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int val);
void show_int(int val);
void show_float(float fval);
void show_pointer(void *pval);
void test_show_bytes(int val);

int main(void){
    //int val = 0x87654321;
    //byte_pointer valp = (byte_pointer)&val;
    // show_bytes(valp, 1);
    //show_bytes(valp, 2);
    //show_bytes(valp, 3);
    const char *s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));
    return 0;
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void show_bytes(byte_pointer start, int len){
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}


void show_int(int val){
    printf("%d", val);
}

void show_float(float fval){
    printf("%.5f", fval);
}

void show_pointer(void *pval){
    printf("%p", pval);
}

void inplace_swap(int *x, int *y){
    *y = *x ^ *y; //Step 1:
    *x = *x ^ *y;
    *y = *x ^ *y;
}











	

    



