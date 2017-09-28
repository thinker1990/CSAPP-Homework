#include <stdio.h>

typedef unsigned float_bits;

// Compute 2*f. If f is NaN, then return f.
float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF) {
        return f;
    }
    else if (exp == 0) {
        frac = frac << 1;
    }
    else if (exp == 0xFF - 1) {
        exp = 0xFF;
        frac = 0;
    }
    else {
        exp = exp + 1;
    }

    return (sign << 31) | (exp << 23) | frac;
}

