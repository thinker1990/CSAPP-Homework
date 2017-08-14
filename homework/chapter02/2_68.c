#include <stdio.h>

int lower_one_mask(int n)
{
    unsigned mask = ~0;
    int bits_of_int = sizeof(int) << 3;
    int right_shift = bits_of_int - n;
    mask = mask >> right_shift;

    return (int)mask;
}

int main(void)
{
    int n;

    n = 6;
    printf("0X%.8X\n", lower_one_mask(n));
    n = 17;
    printf("0X%.8X\n", lower_one_mask(n));
    n = 1;
    printf("0X%.8X\n", lower_one_mask(n));
    n = 32;
    printf("0X%.8X\n", lower_one_mask(n));

    return 0;
}
