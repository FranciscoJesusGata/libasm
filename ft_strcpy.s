# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 23:38:23 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/10 17:43:37 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

				global ft_strcpy
				section .text

ft_strcpy:
				mov			rcx, -1
				cmp			byte [rsi], 0x0				;if(rsi == 'NULL'): return NULL
				je			return_null
loop:
				mov			al, [rsi + rcx]				;al = rsi[rcx]
				mov			[rdi + rcx], al				;rdi[rcx] = al
				inc			rcx							;rcx++
				cmp			byte [rsi + rcx], 0x0		;while(rsi[rcx] != '\0')
				jne			loop
				
return:
				mov			byte[rdi + rcx], 0x0		;rdi[rcx] = '\0'
				mov			rax, rdi					;return rdi
				ret

return_null:
				mov			byte[rax], 0x0
				ret
