#include <stdio.h>

int int_size_is_32()
{
    int x1 = 0x80000000;
    int x2 = 0x7FFFFFFF;

    return x1 < 0 && x2 > 0;
}

int main(void)
{
    printf("int size is 32: %d\n", int_size_is_32());
    
    return 0;
}
