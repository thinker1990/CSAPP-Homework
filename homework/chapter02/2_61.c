#include <limits.h>
#include <stdio.h>

int is_any_bit_equals_1(int x)
{
    return  !(!x);
}

int is_any_bit_equals_0(int x)
{
    return !(!(~x));
}

int is_any_bit_of_last_byte_equals_1(int x)
{
    int offset = (sizeof(int) - 1) << 3;

    return is_any_bit_equals_1(x << offset);
}

int is_any_bit_of_first_byte_equals_0(int x)
{
    int offset = (sizeof(int) - 1) << 3;
    int mask = -1 << offset;

    return is_any_bit_equals_0(x | ~mask);
}

int main(void)
{
    printf("%d\n", is_any_bit_equals_1(1));
    printf("%d\n", is_any_bit_equals_1(15));
    printf("%d\n", is_any_bit_equals_1(0));

    printf("%d\n", is_any_bit_equals_0(15));
    printf("%d\n", is_any_bit_equals_0(0));
    printf("%d\n", is_any_bit_equals_0(-1));

    printf("%d\n", is_any_bit_of_last_byte_equals_1(2));
    printf("%d\n", is_any_bit_of_last_byte_equals_1(256));

    printf("%d\n", is_any_bit_of_first_byte_equals_0(3));
    printf("%d\n", is_any_bit_of_first_byte_equals_0(-1));

    return 0;
}
