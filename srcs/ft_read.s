extern ___error

global _ft_read

_ft_read:
	mov rax, 0x2000003
	syscall
	jc get_errno
	ret
get_errno:
	push rax
	call ___error
	pop qword[rax]
	mov rax, -1
	ret
