# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 22:09:41 by ncontin           #+#    #+#              #
#    Updated: 2024/11/08 11:27:51 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_print_char.c ft_print_hex.c ft_print_nbr.c ft_print_str.c ft_print_uns.c ft_printf.c ft_print_ptr.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
RM = rm -f

all: ${NAME}

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	$(RM) ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re






