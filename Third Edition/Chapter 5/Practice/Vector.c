#include "Vector.h"
vec_ptr new_vec(long len){
    //Allocate header structure:
    vec_ptr result = malloc(sizeof(vec_rec));
    data_t *data = NULL;
    if (!result){ // == NULL
	fprintf(stderr, "Cannot allocate storage for vec_ptr. Abort.");
	return NULL;
    }
    result->len = len;
    if (len > 0){
	data = calloc(len, sizeof(data_t));
	if (!data){
	    fprintf(stderr, "Cannot allocate storage for data_t. Abort.");
	    free(result);
	    return NULL;
	}
    }
    //Data will either be NULL or allocated array:
    result->data = data;
    return result;
}

/*
 * Retrieve vector element and store at dest.
 * Return 0 (out of bounds) or 1 (successful)
 */

int get_vec_element(vec_ptr v, long index, data_t *dest){
    if (index < 0 || index >= v->len)
	return 0;
    *dest = v->data[index];
    return 1;
}

int vec_length(vec_ptr v){
    return v->len;
}
data_t *get_vec_start(vec_ptr v){
    return v->data;
}
    
       
