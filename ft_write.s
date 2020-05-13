# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 19:23:52 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/13 15:04:35 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		extern __errno_location
		global ft_write
		section .text
ft_write:
		mov rax, 1				;system call for write
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
