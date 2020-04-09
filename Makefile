# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 10:02:35 by lcanales          #+#    #+#              #
#    Updated: 2020/02/14 17:35:52 by lcanales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

RM=rm -f

CFLAGS=-Wall -Wextra -Werror -O3

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I includes/

SRC=checkwidth_prec.c ft_atoi.c ft_calloc.c ft_char.c ft_hex.c ft_htoa.c ft_isdigit.c\
		 ft_itoa.c ft_memset.c ft_numb.c ft_print_pre_ptr.c ft_print_pre_str.c\
		 ft_print_pre.c ft_print_ptg.c ft_print_width.c ft_printf.c ft_printstr.c\
		 ft_ptrhex.c ft_printstr.c ft_ptrtoa.c ft_putchar.c ft_str.c ft_strcpy.c\
		 ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c ft_unumb.c ft_utoa.c\
		 procflags.c procparam.c restart.c

OBJ=$(SRC:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all bonus
