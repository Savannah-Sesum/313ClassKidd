	.file	"addmatsSubr.c"
	.text
	.globl	_addMatracies
	.def	_addMatracies;	.scl	2;	.type	32;	.endef
_addMatracies:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$16, %esp
	movl	$0, -8(%ebp)
	jmp	L2
L3:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %ecx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %ebx
	movl	8(%ebp), %eax
	addl	%ebx, %eax
	addl	%ecx, %edx
	movl	%edx, (%eax)
	addl	$1, -8(%ebp)
L2:
	cmpl	$4, -8(%ebp)
	jle	L3
	nop
	nop
	movl	-4(%ebp), %ebx
	leave
	ret
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$80, %esp
	call	___main
	pxor	%xmm0, %xmm0
	movups	%xmm0, 40(%esp)
	movd	%xmm0, 56(%esp)
	movl	$1, 40(%esp)
	pxor	%xmm0, %xmm0
	movups	%xmm0, 20(%esp)
	movd	%xmm0, 36(%esp)
	movl	$2, 20(%esp)
	leal	20(%esp), %eax
	movl	%eax, 8(%esp)
	leal	40(%esp), %eax
	movl	%eax, 4(%esp)
	leal	60(%esp), %eax
	movl	%eax, (%esp)
	call	_addMatracies
	movl	$1, %eax
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev3, Built by MSYS2 project) 14.2.0"
