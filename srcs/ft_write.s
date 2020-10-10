extern ___error

global _ft_write

_ft_write:
	mov rax, 0x2000004
	syscall
	jc get_errno
	ret
get_errno:
	push rax
	call ___error
	pop qword[rax]
	mov rax, -1
	ret
