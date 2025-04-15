	.file	"addmats.cpp"
	.text
	.section	.text$_ZN15MatrixFunctionsC1Ei,"x"
	.linkonce discard
	.align 2
	.globl	_ZN15MatrixFunctionsC1Ei
	.def	_ZN15MatrixFunctionsC1Ei;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN15MatrixFunctionsC1Ei
_ZN15MatrixFunctionsC1Ei:
.LFB2:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN15MatrixFunctions12addMatraciesEPiS0_S0_,"x"
	.linkonce discard
	.align 2
	.globl	_ZN15MatrixFunctions12addMatraciesEPiS0_S0_
	.def	_ZN15MatrixFunctions12addMatraciesEPiS0_S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN15MatrixFunctions12addMatraciesEPiS0_S0_
_ZN15MatrixFunctions12addMatraciesEPiS0_S0_:
.LFB3:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	%r9, 40(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L3
.L4:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %r8
	movq	24(%rbp), %rax
	addq	%r8, %rax
	addl	%ecx, %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
.L3:
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L4
	nop
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$144, %rsp
	.seh_stackalloc	144
	.seh_endprologue
	call	__main
	pxor	%xmm0, %xmm0
	movups	%xmm0, -64(%rbp)
	movd	%xmm0, -48(%rbp)
	movl	$1, -64(%rbp)
	pxor	%xmm0, %xmm0
	movups	%xmm0, -96(%rbp)
	movd	%xmm0, -80(%rbp)
	movl	$2, -96(%rbp)
	leaq	-100(%rbp), %rax
	movl	$5, %edx
	movq	%rax, %rcx
	call	_ZN15MatrixFunctionsC1Ei
	leaq	-96(%rbp), %r8
	leaq	-64(%rbp), %rcx
	leaq	-32(%rbp), %rdx
	leaq	-100(%rbp), %rax
	movq	%r8, %r9
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZN15MatrixFunctions12addMatraciesEPiS0_S0_
	movl	$1, %eax
	addq	$144, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev3, Built by MSYS2 project) 14.2.0"
