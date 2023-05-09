#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>


//1 << 1 = 0b00000010
//1 << 2 = 0b00000100
//1 << 3 = 0b00001000
//1 << 4 = 0b00010000
// etc.

// Read the value of a bit in n and index i
// the basic idea is to shift a 1 to the index you want
// to check, then AND that with the number you are checking
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
bool check_bit(uint8_t n, uint8_t i) {

    if ((n & (1 << i)) != 0) {
        return 1;
    }
    else {
        return 0;
    }
}


// Setting a bit
// in this case we set the mask to be all zeros, except
// a 1 at the index of the bit we want to set. Then we OR
// the number with the mask n | mask
// Example:
// n = 0b00001100
// i = 4
// v = 1
// mask = 1 << i
// n = (n | mask) == 0b00011100
// Note that (O | a) == a, (1 | a) == 1

// set the bit in at index i in n high
uint8_t set_bit(uint8_t n, uint8_t i) {
        uint8_t mask = 1 << i; // all 0's, except 1 at index i
        return n | mask;
}

// Clearing a bit
// in this case, we set the mask to be all 1's except
// a 0 at the index we want to clear. An easy way to get
// this mask is to just do ~(1 << index).
// Then we AND the number withe mask (n & mask)
// Note that (1 & a) == a, (0 & a) == 0
uint8_t clear_bit(uint8_t n, uint8_t i) {
    uint8_t mask; 
    mask = ~(1 << i); // all 1's, except 0 at index i
    return n & mask;
}


// Toggle a bit
// here we will use a mask of all zeros, with a 1 at the index
// we are looking to toggle, mask = 1 << i
uint8_t toggle_bit(uint8_t n, uint8_t i) {
    uint8_t mask = 1 << i;
    return n ^ mask;
}


int main(void) {
    
    // Test check_bit
    assert(check_bit(0b00001011,0) == 1);
    assert(check_bit(0b00001011,1) == 1);
    assert(check_bit(0b00001011,2) == 0);
    assert(check_bit(0b00001011,3) == 1);

    // Test set_bit
    uint8_t n;
    n = 0b00001011;
    n = set_bit(n, 2);
    assert(check_bit(n, 2) == 1);
    n = set_bit(n, 4);
    assert(check_bit(n, 4) == 1);
    

    // Test clear_bit
    n = clear_bit(n, 0);
    assert(check_bit(n, 0) == 0);
    n = clear_bit(n, 3);
    assert(check_bit(n, 3) == 0);

    // Test toggle_bit
    n = 0b00001010;
    assert(toggle_bit(n,0) == 0b00001011);

    return 0;
}








