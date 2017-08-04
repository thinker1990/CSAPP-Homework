#include <stdio.h>

int int_shifts_are_arithmetic()
{
    int all_bit_1 = ~0;

    return all_bit_1 >> 1 == all_bit_1;
}

int main(void)
{
    printf("this machine use arithmetic right shift: %d\n", int_shifts_are_arithmetic());
    
    return 0;
}
