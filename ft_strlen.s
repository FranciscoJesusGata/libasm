# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 15:50:33 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/10 17:40:00 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global ft_strlen
		section .text
ft_strlen:
		mov		rax, -1						;initialize rax to use as a counter
loop:
		inc		rax							;rax++
		cmp		byte [rdi + rax], 0x0		;while(rdi[rax] != '\0')
		jne		loop
		ret									;return rax
