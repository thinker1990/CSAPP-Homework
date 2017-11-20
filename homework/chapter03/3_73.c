/*
    .file	"3_73.c"
	.text
	.globl	find_range
	.type	find_range, @function
find_range:
.LFB11:
	.cfi_startproc
	xorps	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	ja	.L8
	je	.L6
	jb	.L5
.L10:
	movl	$3, %eax
	ret
.L8:
	movl	$2, %eax
	ret
.L5:
	movl	$0, %eax
	ret
.L6:
	movl	$1, %eax
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
