# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 19:23:52 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/10 17:22:10 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global ft_write
		section .text
ft_write:
		mov rax, 1				;system call for write
		syscall
		ret
