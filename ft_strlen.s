# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 15:50:33 by fgata-va          #+#    #+#              #
#    Updated: 2020/04/11 10:26:13 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global _ft_strlen
		section .text
_ft_strlen:
		mov		rax, -1
_loop:
		inc		rax
		cmp		byte [rdi + rax], 0x0
		jne		_loop
		ret
