/*
    .file	"3_74.c"
	.text
	.globl	find_range
	.type	find_range, @function
find_range:
.LFB11:
	.cfi_startproc
    movq  $1, %rax
    movq  $0, %r8
    movq  $2, %r9
    movq  $3, %r10
	xorps	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	cmovaq	%r9, %rax
	cmovbq	%r8, %rax
	cmovpq  %r10, %rax
	ret
	.cfi_endproc
.LFE11:
	.size	find_range, .-find_range
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC0:
	.long	0
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-16)"
	.section	.note.GNU-stack,"",@progbits
*/
