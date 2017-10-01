#include <stdio.h>

typedef unsigned float_bits;

// Compute 0.5*f. If f is NaN, then return f.
float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    unsigned round_to_even = (frac & 0x03) == 0x03;

    if (exp == 0xFF) {
        return f;
    }
    else if (exp == 0) {
        frac += round_to_even;
        frac >>= 1;
    }
    else if (exp == 1) {
        exp = 0;
        frac += round_to_even;
        frac >>= 1;
        frac |= (1 << 31);
    }
    else {
        exp -= 1;
    }

    return (sign << 31) | (exp << 23) | frac;
}

