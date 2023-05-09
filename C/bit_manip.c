#include<stdbool.h>
#include<stdio.h>
#include <assert.h>


//1 << 1 = 0b00000010
//1 << 2 = 0b00000100
//1 << 3 = 0b00001000
//1 << 4 = 0b00010000
// etc.

// the basic idea is to shift a 1 to the index you want
// to check, then & that with the number you are checking
// if the result is non-zero, then there must be a 1 at
// the position you are intested in, so the bit is set.
// otherwise if it is zero then the bit is not set.
//
// Example:
// n = 0b00000100
// index_to_check = 2
// (1 << index_to_check) == 0b00000100
// result = n & (1 << index_to_check) == 0b00000100
// result is non-zero so we know
// Note: we alternatively can check n & (1 << index) == (1 << index)


bool check_bit(int n, int index) {

    if ((n & (1 << index)) != 0) {
        printf("bit at index %d is ON\n", index+1);
        return true;
    }
    else {
        printf("bit at index %d is OFF\n", index+1);
        return false;
    }
}



int main(void) {
    
    check_bit(0b00001011,0);
    check_bit(0b00001011,1);
    check_bit(0b00001011,2);
    check_bit(0b00001011,3);

    return 0;
}
