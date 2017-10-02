#include <stdio.h>

typedef unsigned float_bits;

// Compute (int)f. 
// If conversion causes overflow or f is NaN, then return 0x80000000.
int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    unsigned bias = 127;
    unsigned E;
    unsigned M;
    unsigned val;

    if (exp < bias) {
        val = 0;
    }
    else if (exp >= bias+31) {
        val = 0x80000000;
    }
    else {
        M = frac | (1 << 23);
        E = exp - bias;
        if (E > 23) {
            val = M << (E - 23);
        } else {
            val = M >> (23 - E);
        }
    }

    return sign ? val : -val;
}

