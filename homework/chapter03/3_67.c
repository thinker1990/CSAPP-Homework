/*
 * A. M[%rsp_eval] -> x
 *    M[%rsp_eval + 8] -> y
 *    M[%rsp_eval + 16] -> &z
 *    M[%rsp_eval + 24] -> z
 *
 * B. %rdi -> %rsp_eval + 64
 *
 * C. 24(%rsp_process) == 24(%rsp_eval - 8) == %rsp_eval + 16 -> s.p
 *    16(&rsp_process) == 16(%rsp_eval - 8) == %rsp_eval + 8  -> s.a[1]
 *    8(%rsp_process)  == 8(%rsp_eval - 8)  == %rsp_eval      -> s.a[0]
 *
 * D. M[%rdi] -> M[%rsp_eval + 64] -> r.u[0] -> 16(%rsp_process) -> s.a[1]
 *    M[%rdi + 8] -> M[%rsp_eval + 72] -> r.u[1] -> 8(%rsp_process) -> s.a[0]
 *    M[%rdi + 16] -> M[%rsp_eval + 80] -> r.q -> M[24(%rsp_process)] -> *s.p
 *
 * E. M[%rsp_eval + 64] -> y
 *    M[%rsp_eval + 72] -> x
 *    M[%rsp_eval + 80] -> z
 *
 * F. Struct address is not directly passed as parameter into the process.
 *
 * */
