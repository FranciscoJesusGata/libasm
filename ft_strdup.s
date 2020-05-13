# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 13:55:56 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/13 16:44:06 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
			cmp rdi, 0x0		;if (rdi == NULL) {return NULL;}
			jz return_null
			call ft_strlen
			push rdi			;save s1
			mov rdi, rax		;rdi = strlen(s1); (rax contains the first argument len)
			call malloc			;rax = malloc(rdi)
			cmp rax, 0x0		;if (rax == NULL) {return NULL;}
			jz return_null
			pop rsi				;save s1 in rsi
			mov rdi, rax		;rax = ft_strcpy(s1, src);
			call ft_strcpy
			ret
return_null:
			mov rax, 0x0
			ret

