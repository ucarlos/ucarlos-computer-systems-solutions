#include "../common_header.h"

// #define M  -- Mystery number 1
// #define N -- Mystery number 2

/* -- 
int arith(int x, int y){
    int result = 0;
    result = x * M + y / N;
    return result;
}
*/

/* We compiled this code for particular values of M and N. The compiler
 * optimized the multiplication and division using the methods we have
 * discussed. The following is a translation of the generated machine
 * code back into C:
 */

// Translation of assembly code for arith
int optartith(int x, int y){
    int t = x;
    x <<= 5;
    x -= t;
    if (y < 0) y += 7;

    y >>= 3; // Arithmetic Shift
    return x + y;
}
//What are the values of M and N?

int main(void){

    return 0;

}
