#include <stdio.h>

int leftmost_one(unsigned x)
{
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;

    return x ^ x >> 1;
}

int main(void)
{
    unsigned x = 0;

    x = 0xFF00;
    printf("0x%.8x left most 1 mask is: 0x%.8x\n", x, leftmost_one(x));
    x = 0x6600;
    printf("0x%.8x left most 1 mask is: 0x%.8x\n", x, leftmost_one(x));
    x = 0x0000;
    printf("0x%.8x left most 1 mask is: 0x%.8x\n", x, leftmost_one(x));
    x = 0xFFFFFFFF;
    printf("0x%.8x left most 1 mask is: 0x%.8x\n", x, leftmost_one(x));

    return 0;
}
