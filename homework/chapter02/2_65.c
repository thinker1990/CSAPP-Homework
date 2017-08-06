#include <stdio.h>

/* Return 1 when x contains an odd number of 1s; 0 otherwise.
 * Assume w = 32 */
int odd_ones(unsigned x)
{
    unsigned high_16_bits = x >> 16;                  // step 1
    unsigned xor_16_bits = high_16_bits ^ x;          // step 2 
    unsigned high_8_bits = xor_16_bits >> 8;          // step 3
    unsigned xor_8_bits = high_8_bits ^ xor_16_bits;  // step 4
    unsigned high_4_bits = xor_8_bits >> 4;           // step 5
    unsigned xor_4_bits = high_4_bits ^ xor_8_bits;   // step 6
    unsigned high_2_bits = xor_4_bits >> 2;           // step 7
    unsigned xor_2_bits = high_2_bits ^ xor_4_bits;   // step 8
    unsigned high_1_bit = xor_2_bits >> 1;            // step 9
    unsigned xor_1_bit = high_1_bit ^ xor_2_bits;     // step 10

    return xor_1_bit & 0x01;                          // step 11
}

int main(void)
{
    unsigned x;

    x = 1;
    printf("%u has odd ones: %d\n", x, odd_ones(x));
    x = 3;
    printf("%u has odd ones: %d\n", x, odd_ones(x));
    x = 7;
    printf("%u has odd ones: %d\n", x, odd_ones(x));
    
    return 0;
}
