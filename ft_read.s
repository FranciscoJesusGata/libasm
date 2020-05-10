# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/10 17:23:39 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/10 17:33:39 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			global ft_read
			section .text
ft_read:
			mov rax, 0				;system call for read
			syscall
			ret
