# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 13:12:10 by ncontin           #+#    #+#              #
#    Updated: 2025/01/21 11:35:06 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -lX11 -lXext -lm
RM = rm -f
SRC = so_long.c
OBJ = $(SRC:.c=.o)
INCLUDES = -I./libft -I./ft_printf
LIBS = libft/libft.a ft_printf/libftprintf.a

all: $(NAME)

mlx:
	make -C mlx

$(NAME):$(OBJ)
	make all -C libft
	make all -C ft_printf
	$(CC) $(OBJ) $(MLX_FLAGS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re mlx

