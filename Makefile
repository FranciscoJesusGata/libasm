# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgata-va </var/mail/fgata-va>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 18:47:17 by fgata-va          #+#    #+#              #
#    Updated: 2020/07/03 12:05:19 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

ASM = nasm

FORMAT = -felf64

CFLAGS += -Wall -Werror -Wextra -I. -g

SRC = src/ft_strlen.s src/ft_strcpy.s src/ft_strcmp.s src/ft_write.s\
	  src/ft_read.s src/ft_strdup.s

BONUS_SRC = src/ft_atoi_base_bonus.s src/ft_list_push_front_bonus.s\
			src/ft_list_size_bonus.s

OBJS = $(SRC:.s=.o)

BONUS_OBJS = $(BONUS_SRC:.s=.o)

CSRC = main.c libasm_utils.c libasm_refs.c tests.c

BONUS_CSRC = tests_bonus.c libasm_refs_bonus.c libasm_utils_bonus.c

NAME = libasm.a

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

test: all bonus
	$(CC) $(CFLAGS) $(CSRC) $(BONUS_CSRC) -L. -lasm

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
