				global _ft_strcmp
				section .text

_ft_strcmp:
				cmp [rdi], [rsi]
				jne _return_dif
				cmp byte[rdi], 0x0
				je _return
				cmp byte[rsi], 0x0
				je	_return
				cmp byte [rdi], byte [rsi]
				jne _return
				inc rdi
				inc rsi

_return:
				mov rax, [rdi - rsi]
