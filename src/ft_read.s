# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/10 17:23:39 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/14 18:47:50 by fgata-va         ###   ########.fr        #
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
			mov r10, rax
			call __errno_location
			mov qword[rax], r10
			mov rax, -1
			ret
