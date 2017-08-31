#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k)
{
    int sign_mask = INT_MIN;

    int is_negative = !!(x & sign_mask);

    is_negative && (x = x + (1 << k) - 1);

    return x >> k;
}
