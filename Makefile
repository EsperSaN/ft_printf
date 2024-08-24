# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 15:27:20 by pruenrua          #+#    #+#              #
#    Updated: 2022/09/09 12:55:37 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_printnbr.c ft_printchr.c ft_printnbr_u.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
