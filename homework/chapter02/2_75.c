#include <stdio.h>

int signed_high_prod(int, int);

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    // See Equation 2.18
    int w = sizeof(unsigned) << 3;
    int sign_x = x >> (w - 1);
    int sign_y = y >> (w - 1);
    int signed_prod = signed_high_prod(x, y);

    return signed_prod + sign_x * (int)y + sign_y * (int)x;
}
