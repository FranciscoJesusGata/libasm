# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_size_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 22:56:13 by fgata-va          #+#    #+#              #
#    Updated: 2020/07/05 20:06:08 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section .text

		global ft_list_size_bonus
;		int	ft_list_size_bonus(t_list *begin_list)
;		rdi = t_list **begin_list
ft_list_size_bonus:
		xor rax, rax		;i = 0;
		inc rax				;i++;
		cmp rdi, 0			;if (begin_list == NULL)
		je exit				;	return 0;
loop:
		cmp byte[rdi + 8], 0x0	;while (begin_list != NULL)
		je exit
		mov rcx, [rdi + 8]		;begin_list = begin_list->next;
		mov rdi, rcx
		inc rax
		jmp loop
exit:
		ret
