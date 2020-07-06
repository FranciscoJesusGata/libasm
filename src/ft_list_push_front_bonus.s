# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_push_front_bonus.s                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 22:56:13 by fgata-va          #+#    #+#              #
#    Updated: 2020/06/09 20:40:49 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		section .text

		global ft_list_push_front_bonus
		extern malloc
;		void	ft_list_push_front_bonus(t_list **begin_list, void *data)
;		rdi = t_list **begin_list
;		rsi = void *data
;		sizeof(t_list) = 16
;		sizeof(t_list*) = 8
ft_list_push_front_bonus:
	xor rax, rax		;in case of return 0
	cmp rdi, 0			;if (begin_list == NULL)
	je exit				;	return ;
	push rdi
	push rsi
	mov rdi, 16			;allocate the struct
	call malloc			;t_list *new = malloc(sizeof(t_list));
	cmp rax, 0			;if (!new)
	je exit				;	return ;
	pop rsi
	pop rdi
	mov [rax], rsi		;new->data = data
	mov r10, [rdi]		;using aux register cause you can't directly do: mov [rax], [rdi]
	mov [rax + 8], r10	;new->next = *begin_list;
	mov [rdi], rax		;*begin_list = new;
exit:
	ret
