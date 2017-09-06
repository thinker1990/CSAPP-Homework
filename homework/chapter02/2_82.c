// A. (x < y) == (-x > -y) : False eg. x = INT_MIN
// B. ((x + y) << 4) + y - x == 17 * y + 15 * x : True
// C. ~x + ~y + 1 == ~(x + y) : True
// D. (ux - uy) == -(unsigned)(y - x) : True the bit representation is the same
// E. ((x >> 2) << 2) <= x : True

#include <stdio.h>

int main(void)
{
    int x = 1, y = 2;
    unsigned ux = x;
    unsigned uy = y;

    unsigned r = -(unsigned)(y - x);

    printf("%u\n", (ux - uy) == r);
    return 0;
}
