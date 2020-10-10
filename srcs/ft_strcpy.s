global _ft_strcpy

_ft_strcpy:
	xor rax, rax
	xor rcx, rcx
	strcpy_loop:
		mov dl, byte [rsi + rcx]
		mov byte [rdi + rcx], dl
		inc rcx
		cmp byte [rsi + rcx - 1], 0
		jne strcpy_loop
		mov rax, rdi
		ret
