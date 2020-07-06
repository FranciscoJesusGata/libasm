# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_atoi_base_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 22:56:36 by fgata-va          #+#    #+#              #
#    Updated: 2020/06/05 23:17:48 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global ft_atoi_base_bonus
		section .text

ft_validate_base:
		xor r10, r10
loop_base:
		cmp byte[rdi + r10], 0x0
		je end_base_loop
		mov r11, r10
inner_loop:
		inc r11
		cmp byte[rdi + r11], 0x0
		je check_base
		mov r8b, byte[rdi + r10]
		cmp byte[rdi + r11], r8b
		je not_valid
		jmp inner_loop
check_base:
		cmp byte[rdi + r10], 0x20
		je not_valid
		cmp byte[rdi + r10], 0x2B
		je not_valid
		cmp byte[rdi + r10], 0x2D
		je not_valid
		cmp byte[rdi + r10], 0x09
		je not_valid
		cmp byte[rdi + r10], 0x0A
		je not_valid
		cmp byte[rdi + r10], 0x0B
		je not_valid
		cmp byte[rdi + r10], 0x0C
		je not_valid
		cmp byte[rdi + r10], 0x0D
		je not_valid
inc_base_index:
		inc r10
		jmp loop_base
end_base_loop:
		cmp r10, 1
		jle not_valid
		mov rax, 1
		ret
not_valid:
		xor rax, rax
		ret

;		int		ft_atoi_base_bonus(char *str, char *base);
ft_atoi_base_bonus:
		push rdi
		mov rdi, rsi
		call ft_validate_base
		pop rdi
		cmp rax, 0
		je return
		jne start_atoi
inc_str_index:
		inc r11
		jmp clean_str
start_atoi:
		xor rax, rax
		mov rdx, 1
		xor r11, r11
clean_str:
		cmp byte[rdi + r11], 0x20
		je inc_str_index
		cmp byte[rdi + r11], 0x09
		je inc_str_index
		cmp byte[rdi + r11], 0x0A
		je inc_str_index
		cmp byte[rdi + r11], 0x0B
		je inc_str_index
		cmp byte[rdi + r11], 0x0C
		je inc_str_index
		cmp byte[rdi + r11], 0x0D
		je inc_str_index
check_sign:
		cmp byte[rdi + r11], 0x2B
		je iterate_sign
		cmp byte[rdi + r11], 0x2D
		je is_negative
		jne val_num
is_negative:
		neg rdx
iterate_sign:
		inc r11
		jmp check_sign
val_num:
		cmp byte[rdi + r11], 0x0
		je return
		xor r9, r9
		mov r8b, [rdi + r11]
find_value:
		cmp byte[rsi + r9], 0x0
		je return
		cmp byte[rsi + r9], r8b
		jne inc_find_index
store_num:
		imul rax, r10
		add rax, r9
		inc r11
		jmp val_num
inc_find_index:
		inc r9
		jmp find_value
return:
		imul rax, rdx
		ret
