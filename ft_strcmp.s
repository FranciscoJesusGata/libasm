				global _ft_strcmp
				section .text

_ft_strcmp:
				mov cl,byte [rdi]
				mov dl,byte [rsi]
				cmp dl, cl
				jl _less
				jg _greater
				add rdi, byte 1
				add rsi, byte 1
				cmp byte [rsi], 0x0
				je _equal
				cmp byte [rdi], 0x0
				je _equal
				jmp _ft_strcmp
_greater:
				mov rax, 1
				ret
_less:
				mov rax, -1
				ret
_equal:			
				mov rax, 0
				ret
