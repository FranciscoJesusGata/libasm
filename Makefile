# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va </var/mail/fgata-va>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 18:47:17 by fgata-va          #+#    #+#              #
#    Updated: 2020/06/04 22:17:30 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

ASM = nasm

FORMAT = -felf64

CFLAGS += -Wall -Werror -Wextra -I. -g

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

BONUS_SRC = ft_atoi_base_bonus.s

OBJS = $(SRC:.s=.o)

BONUS_OBJS = $(BONUS_SRC:.s=.o)

CSRC = main.c libasm_utils.c tests.c

NAME = libasm.a

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

test: all bonus
	$(CC) $(CFLAGS) $(CSRC) -L. -lasm

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.s
	$(ASM) $(FORMAT) $<
clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME) *.out

re: fclean all
