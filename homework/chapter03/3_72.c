/*
 * A. s2 = s1 - (30 + 8*n) mod 16 = s1 - (8*n + 16) or s1 - (8*n + 24)
 *
 * B. p = (s2 + 15) mod 16
 *
 * C. s1 = 1, n = 3 -> MAX[e1] = 24; 
 *    s1 = 2, n = 2 -> MIN[e1] = 1
 *
 * D. s2 and p alignment is guarantee to be 16.
 *
 * */
