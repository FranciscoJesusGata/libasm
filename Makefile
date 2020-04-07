# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va </var/mail/fgata-va>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 18:47:17 by fgata-va          #+#    #+#              #
#    Updated: 2020/04/07 19:07:21 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

ASM = nasm

FORMAT = -f macho64

CFLAGS += -Wall -Werror -Wextra -L. -lasm

SRC = ft_strlen.s

OBJS = $(SRC:.c=.o)

NAME = libasm.a

$(NAME):
	@$(ASM) $(FORMAT) $(·SC)
	@ar rc $(NAME) $(OBJS)

all: $(NAME)
	$(CC) $(CFLAGS) main.c

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) *.out

