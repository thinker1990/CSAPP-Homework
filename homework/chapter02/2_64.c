#include <stdio.h>

int any_odd_one(unsigned x)
{
    unsigned all_odd_one = 0XAAAA;

    return !!(x & all_odd_one);
}

int main(void)
{
    printf("%d\n", any_odd_one(0));
    printf("%d\n", any_odd_one(1));
    printf("%d\n", any_odd_one(2));
    
    return 0;
}
