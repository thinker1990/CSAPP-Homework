/*
 * A. e1.p = 0
 *    e1.y = 8
 *    e2.x = 0
 *    e2.next = 8
 * 
 * B. 8 + 8 = 16 bytes
 *
 * C. up->e2.x = *(*(up->e2.next).e1.p) - *(up->e2.next).e1.y;
 *
 * */
