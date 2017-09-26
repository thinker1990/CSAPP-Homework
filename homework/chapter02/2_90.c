#include <stdio.h>

float u2f(unsigned u)
{
    float *fp = (float *)&u;
    return *fp;
}

float fpwr2(int x)
{
    // Result exponent and fraction
    unsigned exp, frac;
    unsigned u;

    if (x < -149) {
        // Too small, return 0.0
        exp = 0;
        frac = 0;
    }
    else if (x < -126) {
        // Denormalized result
        exp = 0;
        frac = 1 << (x + 149);
    }
    else if (x < 128) {
        // Normalized result
        exp = 127 + x;
        frac = 0;
    }
    else {
        // Too big, return infinity
        exp = 0xFF;
        frac = 0;
    }

    // Pack exp and frac into 32 bits
    u = exp << 23 | frac;
    // Return as float
    return u2f(u);
}


