#include "../common_header.h"
// COMPILE WITH PROBLEM2_30.c
/*
 * You are assigned the task of writing code for a function tsub_ok, with arguments
 * x and y, that will return 1 if computing x - y does not cause overflow. Having 
 * just written the code for Problem 2.30, you write the following:
 */

// Determine whether arguments can be substracted without overflow:
int tsub_ok_buggy(int x, int y){
	return tadd_ok(x, -y);
}

// For what values of x and y will this function give incorrect results?
// If x and y are T_min, then it will display -T_min incorrectly.

// Writing a corrected version of this function is left as an exercise.
