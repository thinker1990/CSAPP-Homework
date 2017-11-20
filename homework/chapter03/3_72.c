/*
 * A. s2 = s1 - (30 + 8*n) mod 16
 *    when n % 2 == 0 then s2 = s1 - (8*n + 16) 
 *    when n % 2 == 1 then s2 = s1 - (8*n + 24)
 *
 * B. p = (s2 + 15) mod 16
 *
 * C. when (s1 + 15) % 16 == 0 && n % 2 == 1 then MAX(e1) = 24 
 *    when (s1 + 15) % 16 == 1 && n % 2 == 0 then MIN(e1) = 1
 *
 * D. s2 and p alignment is guarantee to be 16.
 *
 * */
