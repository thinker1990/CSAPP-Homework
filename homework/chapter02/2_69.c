#include <stdio.h>

unsigned rotate_left(unsigned x, int n)
{
    int bits_of_unsigned = sizeof(unsigned) << 3;
    unsigned left_part = x << n;
    unsigned right_part = x >> (bits_of_unsigned - n - 1);
    right_part = right_part >> 1;

    return left_part | right_part;
}

int main(void)
{
    unsigned x = 0x12345678;
    int n;

    n = 4;
    printf("0X%.8X\n", rotate_left(x, n));
    n = 20;
    printf("0X%.8X\n", rotate_left(x, n));
    n = 0;
    printf("0X%.8X\n", rotate_left(x, n));

    return 0;
}
