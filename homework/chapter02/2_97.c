#include <stdio.h>

typedef unsigned float_bits;

int leading_1_pos(unsigned u)
{
    int pos = 0;
    while (u) {
        pos++;
        u >>= 1;
    }

    return pos;
}

// Compute (float)i. 
float_bits float_i2f(int i)
{
    unsigned sign = i >> 31;
    unsigned exp;
    unsigned frac;

    unsigned bias = 127;
    unsigned val = sign ? -i : i;

    if (val == 0) {
        exp = 0;
        frac = 0;
    }
    else {
        int leading_pos = leading_1_pos(val);
        int left_shift_count = (32+1 - leading_pos);
        frac = val << left_shift_count;
        exp = bias + left_shift_count + 23;
    }

    return (sign << 31) | (exp << 23) | (frac >> (32-23));
}

