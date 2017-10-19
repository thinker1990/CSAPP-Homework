#include <stdint.h>

typedef __int128 int128_t;

void store_prod(int128_t *dest, int64_t x, int64_t y)
{
    *dest = x * (int128_t) y;
}


store_prod:
	movq	%rsi, %rax      # rax = xl
	movq	%rdx, %rsi      # rsi = yl
	movq	%rdx, %rcx      # rcx = yl
	sarq	$63, %rcx       # rcx = yh
	cqto                    # rdx = xh, rax = xl
	imulq	%rsi, %rdx      # rdx = yl * xh
	imulq	%rax, %rcx      # rcx = xl * yh
	addq	%rdx, %rcx      # rcx = yl * xh + xl * yh
	mulq	%rsi            # [rdx][rax] = yl * xl
	addq	%rcx, %rdx      # [rdx][rax] = (yl * xh + xl * yh) + (yl * xl)
	movq	%rax, (%rdi)
	movq	%rdx, 8(%rdi)
	ret