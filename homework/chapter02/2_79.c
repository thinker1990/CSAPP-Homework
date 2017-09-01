#include <stdio.h>
#include <limits.h>

int mul3div4(int x)
{
    int mul3 = x + (x << 1);
    int is_negative = mul3 & INT_MIN;

    is_negative && (mul3 = mul3 + 4 - 1);

    return mul3 >> 2;
}

int main(void)
{
    int x = 12;
    printf("%d\n", mul3div4(x));
    
    x = -12;
    printf("%d\n", mul3div4(x));
    
    return 0;
}
