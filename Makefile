# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va </var/mail/fgata-va>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 18:47:17 by fgata-va          #+#    #+#              #
#    Updated: 2020/06/02 18:37:11 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

ASM = nasm

FORMAT = -felf64

CFLAGS += -Wall -Werror -Wextra -I. -g

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_atoi_base.s

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

re: fclean all
