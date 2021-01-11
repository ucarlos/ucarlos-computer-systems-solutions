#include "../common_header.h"
/* Consider the following code that attempts to sum the elements of an array a, where
 * the number of elements is given by parameter length:
 */
// WARNING: This is buggy code:

float sum_elements(float *a, unsigned length){
	int i;
	float result = 0;
	
	for (i = 0; i <= length -1; i++) // Comparing b/w signed and unsigned is nono.
		result += a[i];

	return result;
}

float sum_elements_corrected(float *a, unsigned length){
	if (!length) // == 0
		return 0;

	float result = 0;
	for (int i = 0; i < length; i++)
		result += a[i];
	

	return result;
}

int main(void){
        float list[] = {1, 2, 3, 4, 5, 6};
//	printf("%.2f\n",sum_elements(list, 0)); // Will cause segmentation fault
	printf("%.2f\n",sum_elements_corrected(list, 0)); 

}

/* When run with argument length equal to 0, this code should return 0.0. Instead, it
 * encounters a memory error. Explain why this happens. Show how this code can be 
 * corrected.
 */

/* the '<= length - 1' segment will convert i into unsigned, if length is 0, then 0- 1
 * will become 2^32 -1, which will cause a segmentation fault.
 */
