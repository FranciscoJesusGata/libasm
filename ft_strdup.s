# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 13:55:56 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/12 14:16:24 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
			cmp rdi, 0x0
			jz return_null
			push rdi
			mov rdi, rax
			call malloc
			cmp rax, 0x0
			jz return_null
			pop rsi
			mov rdi, rax
			call ft_strcpy
			ret
return_null:
			mov rax, 0x0
			ret

