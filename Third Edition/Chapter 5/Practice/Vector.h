// Defines the Vector struct, which is used throughout Chapter 5 of Randall Bryant's Computer Systems (2015)
#ifndef VECTOR_H
#define VECTOR_H
#include "../../common_header.h"
typedef int data_t;
typedef struct{
    long len;
    data_t *data;
}vec_rec, *vec_ptr;

vec_ptr new_vec(long len);
int get_vec_element(vec_ptr v, long index, data_t *dest);
int vec_length(vec_ptr v);
data_t *get_vec_start(vec_ptr v);

#endif
