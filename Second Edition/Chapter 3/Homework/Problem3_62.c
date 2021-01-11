#include "../../common_header.h"

#define N 13

void transpose(int array[N][N]){
    int i, j;
    for (i = 0; i < N; i++)
	for (j = 0; j < i; j++){
	    int t = array[i][j];
	    array[i][j] = array[j][i];
	    array[j][i] = t;
	}
}

