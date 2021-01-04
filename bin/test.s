.bss
		.zero 4
	a1:
		.align 4
	.section .rodata
STR0:
		.string "test:%d\n"
.text
.globl main
main:
	pushl	%ebp
	movl	%esp,%ebp
	movl	$10,%eax
	movl	%eax,a1
	pushl	a1
	pushl	$STR0
	call	printf
	addl	$8,%esp
	popl	%ebp
	ret
.section .note.GNU-stack,"",@progbits
