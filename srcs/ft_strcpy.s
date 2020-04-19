section .txt:
	global ft_strcpy

ft_strcpy:
	xor rax, rax
	xor rdx, rdx
	strcpy_loop:
		mov al, byte [rsi + rdx]
		mov byte [rdi + rdx], al
		inc rdx
		cmp byte [rsi + rdx - 1], 0
		jne strcpy_loop
		mov rax, rdi
		ret
