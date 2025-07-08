	.file	"fake.c"
	.text
	.p2align 4
	.globl	sockets
	.type	sockets, @function
sockets:
.LFB0:
	.cfi_startproc
.L1:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	sockets, .-sockets
	.p2align 4
	.globl	allocations
	.type	allocations, @function
allocations:
.LFB13:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE13:
	.size	allocations, .-allocations
	.p2align 4
	.globl	threads
	.type	threads, @function
threads:
.LFB15:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE15:
	.size	threads, .-threads
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"127.0.0.1:8080"
.LC1:
	.string	"TcpListener socket fd is %d\n"
.LC2:
	.string	"Socket fd is %d\n"
	.text
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
.L5:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$1, %eax
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rbx
	movq	%rbx, 24(%rsp)
	movl	$2, %ebx
#APP
	
mov %rbx, %rdi
mov %rax, %rsi
xor %rdx, %rdx
mov $0x29, %rax
syscall

#NO_APP
	xorl	%esi, %esi
	movq	%rax, %rbx
	movl	$49, %ecx
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rdx
	.p2align 5
	.p2align 4
	.p2align 3
.L6:
	cmpb	$58, %cl
	cmove	%eax, %esi
	addq	$1, %rax
	movzbl	(%rdx,%rax), %ecx
	testb	%cl, %cl
	jne	.L6
.L7:
	leal	1(%rsi), %eax
	movslq	%esi, %rsi
	xorl	%ecx, %ecx
	cltq
	movzbl	(%rdx,%rax), %eax
	addq	%rsi, %rdx
	testb	%al, %al
	je	.L9
	.p2align 5
	.p2align 4
	.p2align 3
.L11:
	subl	$48, %eax
	leal	(%rcx,%rcx,4), %ecx
	addq	$1, %rdx
	movzbl	%al, %eax
	leal	(%rax,%rcx,2), %ecx
	movzbl	1(%rdx), %eax
	testb	%al, %al
	jne	.L11
	rolw	$8, %cx
.L9:
	movl	$0, (%rsp)
	leaq	1+.LC0(%rip), %rsi
	xorl	%r8d, %r8d
	movl	$49, %edx
	.p2align 6
	.p2align 4
	.p2align 3
.L12:
	cmpb	$46, %dl
	je	.L30
.L14:
	movslq	%r8d, %rdi
	addq	$1, %rsi
	movzbl	(%rsp,%rdi), %eax
	leal	(%rax,%rax,4), %eax
	leal	-48(%rdx,%rax,2), %eax
	movzbl	-1(%rsi), %edx
	movb	%al, (%rsp,%rdi)
	cmpb	$58, %dl
	jne	.L12
.L15:
	movl	(%rsp), %eax
	movl	$2, %edx
	movw	%cx, 2(%rsp)
	movl	$16, %ecx
	movw	%dx, (%rsp)
	movl	%eax, 4(%rsp)
	movq	%rsp, %rax
#APP
	
mov %rbx, %rdi
mov %rax, %rsi
mov %rcx, %rdx
mov $0x31, %rax
syscall

	
mov %rbx, %rdi
mov $256, %rsi
mov $0x32, %rax
syscall

#NO_APP
	leaq	.LC1(%rip), %rdi
	movq	%rbx, %rsi
	xorl	%eax, %eax
	call	printf@PLT
	leaq	.LC2(%rip), %rbp
	.p2align 4
	.p2align 3
.L28:
.L18:
.L16:
#APP
	
mov %rbx, %rdi
xor %rsi, %rsi
xor %rdx, %rdx
mov $0x2b, %rax
syscall

#NO_APP
	movq	%rax, %rsi
	movq	%rbp, %rdi
	xorl	%eax, %eax
	call	printf@PLT
	jmp	.L28
	.p2align 4,,10
	.p2align 3
.L30:
.L13:
	movzbl	(%rsi), %edx
	addq	$1, %rsi
	addl	$1, %r8d
	cmpb	$58, %dl
	jne	.L12
	jmp	.L15
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20250405"
	.section	.note.GNU-stack,"",@progbits
