# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va </var/mail/fgata-va>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 18:47:17 by fgata-va          #+#    #+#              #
#    Updated: 2020/05/09 17:15:55 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

ASM = nasm

FORMAT = -felf64

CFLAGS += -Wall -Werror -Wextra -I.

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s

OBJS = $(SRC:.s=.o)

CSRC = main.c libasm_utils.c tests.c

NAME = libasm.a

all: $(NAME)
	    $(CC) $(CFLAGS) $(CSRC) -L. -lasm

$(NAME):
	@for file in $(SRC); do $(ASM) $(FORMAT) $${file}; done
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) *.out

