#include "../../common_header.h"

/*
 * An alternative rule for translating if statements into goto code is as 
 * follows:
 * 
 * t = test-expr;
 * if (t)
 *    goto true;
 * else-statement
 *    goto done;
 * true:
 *    then-statement
 * done:
 *
 * A) Rewrite the goto version of absdiff based on this alternative rule. 
 *
 * B) Can you think of any reasons for choosing one rule over the other.
 *    This alternative method is easier to read than the other(jump for 
 *    nonpassing conditions).
 * ---------------------------------------------------------------------------
 * The first conditional branch is part of the implementation of the &&
 * expression. If the test for p being non-null fails, the code will 
 * skip the test of a > 0.
 * ---------------------------------------------------------------------------
 */

int absdiff(int x, int y){
    int test = x < y;
    if (test)
	goto correct;
    else
	goto done;

correct:
    return y - x;
done:
    return x - y;
    
}

int absdiff_correct(int x, int y){
    int result;
    if (x < y)
	goto correct;
    result = x - y;
    goto done;

correct:
    result = y - x;
done:
    return result;
}
 

int main(void){

    return 0;
}
