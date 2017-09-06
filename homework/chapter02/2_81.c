#include <stdio.h>

unsigned A(int k)
{
    unsigned all_1 = ~0;

    return all_1 << k;
}

unsigned B(int k, int j)
{
    // a more elegant solution from : https://dreamanddead.gitbooks.io/csapp-3e-solutions/content/chapter2/2.81.html
    // ~(-1 << k) << j

    unsigned low_j_0 = A(j);
    unsigned low_k_plus_j_0 = A(k + j);

    return low_j_0 & ~low_k_plus_j_0;
}

int main(void)
{
    unsigned x = A(16);
    printf("0X%.8X\n", x);
    
    unsigned y = B(8, 8);
    printf("0X%.8X\n", y);
    
    return 0;
}
