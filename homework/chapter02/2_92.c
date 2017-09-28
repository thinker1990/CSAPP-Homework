#include <stdio.h>

typedef unsigned float_bits;

// Compute -f. If f is NaN, then return f.
float_bits float_negate(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF && frac != 0) {
        return f;
    }

    return (~sign << 31) | (exp << 23) | frac;
}

