#include "../common_header.h"

/* You are given the assignment of writing a function that determines whether one
 * string is longer than another. You decide to make use of the string library function
 * strlen having the following declaration:
 */

// size_t strlen(const char *s);

// Here is your first attempt at the function:
/* Determine whether string s is longer than string t */
/* WARNING: This function is buggy */
int strlonger(char *s, char *t){
	return (strlen(s) - strlen(t) > 0);
  
}
int main(void){
	



}
