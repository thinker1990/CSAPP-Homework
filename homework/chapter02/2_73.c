#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    int sum = x + y;
    int sign_bit_mask = INT_MIN;

    // x > 0 && y > 0 && sum < 0 -> positive overflow
    int is_positive_overflow = !(x & sign_bit_mask) && !(y & sign_bit_mask) && (sum & sign_bit_mask);
    // x < 0 && y < 0 && sum > 0 -> negative overflow
    int is_negative_overflow = (x & sign_bit_mask) && (y & sign_bit_mask) && !(sum & sign_bit_mask);

    (is_positive_overflow && (sum = INT_MAX)) || (is_negative_overflow && (sum = INT_MIN));

    return sum;
}

int main(void)
{
    int a = 0;
    int b = 0;

    a = INT_MAX; b = 10;
    printf("%d + %d = %d\n", a, b, saturating_add(a, b));
    
    a = INT_MIN; b = -10;
    printf("%d + %d = %d\n", a, b, saturating_add(a, b));
    
    a = 1024; b = 2048;
    printf("%d + %d = %d\n", a, b, saturating_add(a, b));

    return 0;
}
