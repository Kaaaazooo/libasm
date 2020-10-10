global _ft_strcmp

_ft_strcmp:
	strcmp_loop:
		xor rax, rax
		mov al, byte [rdi]
		cmp al, byte [rsi]
		jne return_diff
		cmp al, 0
		je return_diff
		inc rdi
		inc rsi
		jmp strcmp_loop
	return_diff:
		movzx rdx, byte[rsi]
		sub rax, rdx
		ret
