global _ft_strlen

_ft_strlen:
	xor rax,rax
	_strlen_loop:
		cmp byte [rdi+rax],0
		je _return
		inc rax
		jmp _strlen_loop
	_return:
		ret
