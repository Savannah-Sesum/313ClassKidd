	.file	"addmatsSimple.c"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$64, %esp
	call	___main
	pxor	%xmm0, %xmm0
	movups	%xmm0, 20(%esp)
	movd	%xmm0, 36(%esp)
	movl	$1, 20(%esp)
	pxor	%xmm0, %xmm0
	movups	%xmm0, (%esp)
	movd	%xmm0, 16(%esp)
	movl	$2, (%esp)
	movl	$0, 60(%esp)
	jmp	L2
L3:
	movl	60(%esp), %eax
	movl	20(%esp,%eax,4), %edx
	movl	60(%esp), %eax
	movl	(%esp,%eax,4), %eax
	addl	%eax, %edx
	movl	60(%esp), %eax
	movl	%edx, 40(%esp,%eax,4)
	addl	$1, 60(%esp)
L2:
	cmpl	$4, 60(%esp)
	jle	L3
	movl	$1, %eax
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev3, Built by MSYS2 project) 14.2.0"
