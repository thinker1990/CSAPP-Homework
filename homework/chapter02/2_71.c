#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    int first_left_shift_bits = (3 - bytenum) << 3;
    int then_right_shift_bits = 3 << 3;

    return ((int)word << first_left_shift_bits) >> then_right_shift_bits;
}

int main(void)
{
    packed_t word = 0X12F456F8;

    printf("%d byte of 0X%X is: 0X%.8X\n", 0, word, xbyte(word, 0));
    printf("%d byte of 0X%X is: 0X%.8X\n", 1, word, xbyte(word, 1));
    printf("%d byte of 0X%X is: 0X%.8X\n", 2, word, xbyte(word, 2));
    printf("%d byte of 0X%X is: 0X%.8X\n", 3, word, xbyte(word, 3));
    
    return 0;
}
