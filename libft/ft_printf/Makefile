# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 05:44:02 by atchougo          #+#    #+#              #
#    Updated: 2022/02/13 20:21:30 by atchougo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = gcc
FLAGS   = -Wall -Wextra -Werror

SRCS    = ft_printf.c ft_printf_utils.c

OBJS    = ${SRCS:.c=.o}
LIBFT   = ./libft/libft.a

all : ${NAME} ${LIBFT}

${NAME} : ${OBJS} ft_printf.h ${LIBFT}
	cp libft/libft.a ${NAME}
	ar rcs ${NAME} ${OBJS}

clean :
	make -C ./libft clean
	rm -f ${OBJS}

fclean : clean
	make -C ./libft fclean
	rm -f ${NAME}

re : fclean all

${LIBFT} : 
	make -C ./libft/

.c.o : ${SRCS} ft_printf.h
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

.PHONY		:	all re clean fclean
