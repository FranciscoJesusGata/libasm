# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 23:38:23 by fgata-va          #+#    #+#              #
#    Updated: 2020/04/12 19:57:46 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

				global _ft_strcpy
				section .text

_ft_strcpy:
				mov			rcx, -1
				cmp			byte [rsi], 0x0
				je			_return_null
_loop:	
				mov			al, [rsi + rcx]
				mov			[rdi + rcx], al
				inc			rcx
				cmp			byte [rsi + rcx], 0x0
				jne			_loop
				
_return:
				mov			byte[rdi + rcx], 0x0
				mov			rax, rdi
				ret

_return_null:
				mov			byte[rax], 0x0
				ret
