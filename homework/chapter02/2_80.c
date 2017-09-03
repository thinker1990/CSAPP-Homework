#include <stdio.h>
#include <limits.h>

/*
 * source : https://dreamanddead.gitbooks.io/csapp-3e-solutions/content/chapter2/2.80.html
 * 
 * calculate 3/4x, no overflow, round to zero
 *
 * no overflow means divide 4 first, then multiple 3, diffrent from 2.79 here
 *
 * rounding to zero is a little complicated.
 * every int x, equals f(first 30 bit number) plus l(last 2 bit number)
 *
 *   f = x & ~0x3
 *   l = x & 0x3
 *   x = f + l
 *   threeforths(x) = f/4*3 + l*3/4
 *
 * f doesn't care about round at all, we just care about rounding from l*3/4
 *
 *   lm3 = (l << 1) + l
 *
 * when x > 0, rounding to zero is easy
 *
 *   lm3d4 = lm3 >> 2
 *
 * when x < 0, rounding to zero acts like divide_power2 in 2.78
 *
 *   bias = 0x3    // (1 << 2) - 1
 *   lm3d4 = (lm3 + bias) >> 2
 */
int threefourths(int x)
{
    int last2bits_mask = 0x3;
    
    int high_bits_of_x = x & ~last2bits_mask;
    int high_div4 = high_bits_of_x >> 2;
    int high_div4_mul3 = high_div4 + (high_div4 << 1);

    int low_bits_of_x = x & last2bits_mask;
    int low_mul3 = low_bits_of_x + (low_bits_of_x << 1);
    int is_negative = x & INT_MIN;
    int bias = 4 - 1;
    is_negative && (low_mul3 = low_mul3 + bias);
    int low_mul3_div4 = low_mul3 >> 2;

    return high_div4_mul3 + low_mul3_div4;
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
