global ft_read

ft_read:
	mov rax, 0
	syscall
	jc ret_err
	ret
ret_err:
	mov rax, -1
	ret
