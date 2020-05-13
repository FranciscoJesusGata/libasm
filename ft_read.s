# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/10 17:23:39 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/13 15:08:53 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			extern __errno_location
			global ft_read
			section .text
ft_read:
			mov rax, 0		;system call for read
			syscall
			cmp rax, 0
			jl error
			ret
error:
			neg rax
			mov rdi, rax
			call __errno_location
			mov [rax], rdi
			mov rax, -1
			ret
