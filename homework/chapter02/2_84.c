int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    // Get the sign bits
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return (sx == 1 && sy == 0) 
        || (sx == 1 && sy == 1 && ux >= uy) 
        || (sx == 0 && sy == 0 && ux <= uy) 
        || (sx == 0 && sy == 1 && ux == 0 && uy == 0);
}
