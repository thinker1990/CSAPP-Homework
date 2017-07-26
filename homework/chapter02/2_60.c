#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned mask = 0xff << (i * 8);
    unsigned replace_byte = b << (i * 8);

    return (x & ~mask) ^ replace_byte;
}

int main(void)
{
    printf("%x\n", replace_byte(0x12345678, 2, 0xab));
    printf("%x\n", replace_byte(0x12345678, 0, 0xab));
    
    return 0;
}
