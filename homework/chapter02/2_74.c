#include <stdio.h>
#include <limits.h>

int tsub_ok(int x, int y)
{
    if (y == INT_MIN)
    {
        if (x > 0) {
            return 0;
        }
        else {
            return 1;
        }
    }

    int z = -y;
    int sum = x + z;

    int is_positive_overflow = (x > 0) && (z > 0) && (sum < 0);
    int is_negative_overflow = (x < 0) && (z < 0) && (sum > 0);

    return !(is_positive_overflow || is_negative_overflow);
}

int main(void)
{
    int x, y;

    x = 10, y = INT_MIN;
    printf("is substract ok: %d\n", tsub_ok(x, y));
    
    x = -10, y = INT_MAX;
    printf("is substract ok: %d\n", tsub_ok(x, y));
    
    x = -1024, y = INT_MIN;
    printf("is substract ok: %d\n", tsub_ok(x, y));
    
    x = 1024, y = 2048;
    printf("is substract ok: %d\n", tsub_ok(x, y));

    return 0;
}
