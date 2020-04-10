# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va </var/mail/fgata-va>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 18:47:17 by fgata-va          #+#    #+#              #
#    Updated: 2020/04/11 00:00:25 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

ASM = nasm

FORMAT = -fmacho64

CFLAGS += -Wall -Werror -Wextra -L. -lasm -I.

SRC = ft_strlen.s ft_strcpy.s

OBJS = $(SRC:.s=.o)

NAME = libasm.a

all: $(NAME)
	    $(CC) $(CFLAGS) main.c libasm_utils.c

$(NAME):
	@for file in $(SRC); do $(ASM) $(FORMAT) $${file}; done
	ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) *.out

