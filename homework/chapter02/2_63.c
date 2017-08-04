#include <stdio.h>
#include <limits.h>

unsigned calc_compensation(int k)
{
    int int_bit_count = sizeof(int) * 8;
    unsigned compensation = 1;
    for (int i = 0; i < k; i++) {
        compensation *= 2;
    }

    return (compensation - 1) << (int_bit_count - k);
}

unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;

    int xsra_int = xsra;
    if (xsra_int > 0) {
        return xsra;
    }
    else {
        return xsra - calc_compensation(k);
    }
}

int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;

    if (x > 0) {
        return xsrl;
    }
    else {
        unsigned xsrl_unsigned = (unsigned) xsrl;
        xsrl_unsigned += calc_compensation(k);

        return (int) xsrl_unsigned;
    }
}

int main(void)
{
    unsigned ux = (unsigned)INT_MAX + 1;
    unsigned ux_rsl_3 = srl(ux, 3);
    (ux == ux_rsl_3 * 8) && printf("srl function correct.\n");
    
    int x = ~0;
    int x_sra_3 = sra(x, 3);
    (x == x_sra_3) && printf("sra function correct.\n");

    return 0;
}
