#include "common_header.h"
/* Consider the following code that attempts to sum the elements of an array a,
   where the number of elements is given by parameter length:
 */
float sum_elements(float *a, unsigned length){
    //WARNING: This is some buggy code
    int i;
    float result = 0;
    
//  for (i = 0; i <= length - 1; i++) //Buggy part
    for (i = 0; i < (int)length; i++)
	result += a[i];
    return result;
}
int main(void){
    float list[] = {1.5, 2.5, 3.5, 4.5};
    unsigned int length = 0;
    printf("The result of using %d as length in "
	   "sum_elements: %.2f", length, sum_elements(list, length));

    return 0;
}

//When run with argument length equal to 0, this code should return 0.0 Instead
//it encounters a memory error. Explain why this happends. Show how this code
//can be corrected.


/* Correction: Casted length as signed int, and changed the equality.
   Before, length - 1 would be evaulated as a signed number, so in the case of 
   0, it would be -1, which would cause an infinite loop. This will return a 
   segmentation fault error due to the fact that i would go out of the array's
   bounds.
   The casting should change any negative number in a positive number, but
   why would you do that?
*/
