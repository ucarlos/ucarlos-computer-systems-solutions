/* 
   Modify the code for combine5 to unroll the loop by a factor k = 5
   You can compile this program with gcc using:
   gcc Problem5_7.c Vector.c -o Problem5_7
*/
#include "Vector.h"
#define LOOP_FACTOR (5)
#define IDENT (10)
#define OP *
void combine5_normal(vec_ptr v, data_t *dest){
    long i;
    long length = vec_length(v);
    long limit = length - 1;
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    //Combine 2 elements at a time:
    for (i = 0; i < limit; i+=2)
	acc = (acc OP data[i]) OP data[i + 1];

    //Finsh any remaining elements
    for (; i < length; i++)
	acc = acc OP data[i];
    

}

void combine5_problem7(vec_ptr v, data_t *dest){
    long i;
    long length = vec_length(v);
    long limit = length - LOOP_FACTOR + 1;
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    //combine 5 elements at a time:
    for (i = 0; i < limit; i+=5){
	acc = (acc OP data[i]) OP (data[i + 1]) OP (data[i + 2]) OP (data[i + 3]) OP (data[i + 4]);
    }
    //Finish remaining elements
    for (; i < length; i++)
	acc = acc OP data[i];
    *dest = acc;
}
int main(void){
    return 0;
}
