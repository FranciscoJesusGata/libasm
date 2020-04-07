# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va </var/mail/fgata-va>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 18:47:17 by fgata-va          #+#    #+#              #
#    Updated: 2020/04/07 19:31:46 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

ASM = nasm

FORMAT = -fmacho64

CFLAGS += -Wall -Werror -Wextra -L. -lasm

SRC = ft_strlen.s

OBJS = $(SRC:.s=.o)

NAME = libasm.a

$(NAME):
	$(ASM) $(FORMAT) $(SRC)
	ar rc $(NAME) $(OBJS)

all: $(NAME)
	$(CC) $(CFLAGS) main.c

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) *.out

