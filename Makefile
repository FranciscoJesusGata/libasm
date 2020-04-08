# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va </var/mail/fgata-va>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 18:47:17 by fgata-va          #+#    #+#              #
#    Updated: 2020/04/08 23:07:30 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

ASM = nasm

FORMAT = -fmacho64

CFLAGS += -Wall -Werror -Wextra -L. -lasm

SRC = ft_strlen.s

OBJS = $(SRC:.s=.o)

NAME = libasm.a

all: $(NAME)
	    $(CC) $(CFLAGS) main.c

$(NAME):
	$(ASM) $(FORMAT) $(SRC)
	ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) *.out

