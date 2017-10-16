long decode2(long x, long y, long z)
{
    y -= z;
    x *= y;

    long result = y;
    result = (result << 63) >> 63;
    result ^= x;

    return result;
}