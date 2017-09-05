// A. (x < y) == (-x > -y) : False eg. x = INT_MIN
// B. ((x + y) << 4) + y - x == 17 * y + 15 * x : True
// C. ~x + ~y + 1 == ~(x + y) : True
// D. (ux - uy) == -(unsigned)(y - x) : False eg. x = 2, y = 1
// E. ((x >> 2) << 2) <= x : True

#include <stdio.h>

int main(void)
{
    int x = 2, y = 1;
    unsigned ux = x;
    unsigned uy = y;

    printf("%d\n", (ux - uy) == -(unsigned)(y - x));
    return 0;
}
