				global _ft_strcmp
				section .text

_ft_strcmp:
				cmp [rdi], [rsi]
				jne	_return_dif
				cmp byte[rdi], 0x0
				jne
