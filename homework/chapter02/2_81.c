#include <stdio.h>

unsigned left_k_0(int k)
{
    unsigned all_1 = ~0;

    return all_1 << k;
}

unsigned mid_k_1_left_j_0(int k, int j)
{
    unsigned left_j_0 = left_k_0(j);
    unsigned left_k_plus_j_0 = left_k_0(k + j);

    return left_j_0 & ~left_k_plus_j_0;
}

int main(void)
{
    unsigned x = left_k_0(16);
    printf("0X%.8X\n", x);
    
    unsigned y = mid_k_1_left_j_0(8, 8);
    printf("0X%.8X\n", y);
    
    return 0;
}
