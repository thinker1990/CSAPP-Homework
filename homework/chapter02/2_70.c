#include <stdio.h>

int fits_bits(int x, int n)
{
    int bits_of_int = sizeof(int) << 3;
    int shift_size = bits_of_int - n;
    int shift_left_then_right= (x << shift_size) >> shift_size;

    return x == shift_left_then_right;
}

int main(void)
{
    int x, n;

    x = 3;
    n = 3;
    printf("0X%.8X can be represented by %d bits: %d\n", x, n, fits_bits(x, n));
    x = -6;
    n = 5;
    printf("0X%.8X can be represented by %d bits: %d\n", x, n, fits_bits(x, n));
    x = 0xFF;
    n = 8;
    printf("0X%.8X can be represented by %d bits: %d\n", x, n, fits_bits(x, n));
    x = 0xFF;
    n = 9;
    printf("0X%.8X can be represented by %d bits: %d\n", x, n, fits_bits(x, n));

    return 0;
}
