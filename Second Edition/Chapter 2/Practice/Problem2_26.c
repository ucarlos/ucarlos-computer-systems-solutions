#include "common_header.h"
//Prototype for library function strlen
//size_t strlen(const char *s); 

//Determine whether string s is longer than string t
//WARNING: This function is buggy


/* You are given the assignment of writing a function that determines whether one
   string is longer than another. You decide to make use of the string library
   function strlen having the following declaration:
 */

int strlonger(char *s, char *t){
    return strlen(s) - strlen(t) > 0;
}
int main(void){
    

}
