# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va </var/mail/fgata-va>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 18:47:17 by fgata-va          #+#    #+#              #
#    Updated: 2020/04/12 18:32:23 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

ASM = nasm

FORMAT = -fmacho64

CFLAGS += -Wall -Werror -Wextra -L. -lasm -I.

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s

OBJS = $(SRC:.s=.o)

CSRC = main.c libasm_utils.c tests.c

NAME = libasm.a

all: $(NAME)
	    $(CC) $(CFLAGS) $(CSRC)

$(NAME):
	@for file in $(SRC); do $(ASM) $(FORMAT) $${file}; done
	ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) *.out

