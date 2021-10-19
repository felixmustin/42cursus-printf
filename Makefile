# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmustin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 12:51:53 by fmustin           #+#    #+#              #
#    Updated: 2021/10/12 12:46:22 by fmustin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_convert.c

%.o:%.c
	$(CC) $(CCFLAG) -c -o $@ $<

OBJS = ${SRC:.c=.o}

CCFLAG = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all: ${NAME}

bonus:	${OBJS}
		ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all, clean, fclean, re

