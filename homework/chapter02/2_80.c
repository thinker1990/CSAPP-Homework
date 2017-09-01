#include <stdio.h>
#include <limits.h>

int threefourths(int x)
{
    // 3 * x / 4 == x / 2 + x / 4 ~= x / 2 + (x + 1) / 4

    int result;
    // for positive
    !(x & INT_MIN) && (result = (x >> 1) + (((unsigned)x + 1) >> 2));
    // for negative
    (x & INT_MIN) && (result = ((x + 1) >> 1) + ((x + 2) >> 2));

    return result;
}

int main(void)
{
    int x;

    x = INT_MAX;
    printf("%d\n", threefourths(x));
    
    x = 4 + 1;
    printf("%d\n", threefourths(x));
    
    x = 4 + 2;
    printf("%d\n", threefourths(x));
    
    x = 4 + 3;
    printf("%d\n", threefourths(x));

    x = -4 - 1;
    printf("%d\n", threefourths(x));

    x = -4 -2;
    printf("%d\n", threefourths(x));

    x = -4 -3;
    printf("%d\n", threefourths(x));
    
    return 0;
}
