#include <stdio.h>

int mix(int x, int y)
{
    int mask = 0xff;
    int last_byte = x & mask;
    int except_last_byte = y & ~mask;

    return last_byte | except_last_byte;
}

int main(void)
{
    int x = 0x89abcdef;
    int y = 0x76543210;

    printf("%x\n", mix(x, y));

    return 0;
}
