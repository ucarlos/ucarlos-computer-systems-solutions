#include "../common_header.h"
#define BIT_SHIFT_32 (0x80000000)
#define BIT_SHIFT_16 (0x8000)
int int_size_is_32(void);
int int_size_is_16(void);
int main(void){


}

int int_size_is_32(void){
    // Set most significant bit (msb) of 32-bit machine
    int set_msb = 1 << 31;
    // Shift past masb of 32-bit word:
    int beyond_msb = (BIT_SHIFT_32) << 1;

    // set_msb is nonzero when word size >= 32
    // Beyond_msb is zero when word size <= 32
    return set_msb && !(beyond_msb);
}

int int_size_is_16(void){
	int set_msb = 1 << 15;
	int beyond_msb = (BIT_SHIFT_16) << 1;

	return set_msb && !(beyond_msb);
}
