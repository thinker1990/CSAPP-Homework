/* A. x      in %rdi
      n      in %esi
      result in %rax
      mask   in %rdx
 */

/* B. result = 0;
      mask   = 1;
 */

/* C. mask != 0
 */

/* D. mask = mask << n;
 */

/* E. result |= mask & x;
 */

 /* F */
 long loop(long x, int n)
 {
     long result = 0;
     long mask;
     for (mask = 1; mask != 0; mask = mask << n)
     {
         result |= mask & x;
     }

     return result;
 }