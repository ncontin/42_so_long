# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 13:12:10 by ncontin           #+#    #+#              #
#    Updated: 2025/01/28 12:01:34 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	so_long.c\
		parse_map/check_path.c\
		parse_map/check_shape.c\
		parse_map/check_walls.c\
		parse_map/components.c\
		parse_map/read_map.c\
		parse_map/store_grid.c\
		parse_map/validate_map.c\
		draw.c\
		cleanup.c\
		player_move.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lmlx -lmlx -lX11 -lXext -lm
RM = rm -f

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
	$(CC) $(CFLAGS) $(INCLUDES) -I/usr/include -Imlx_linux -O3 -c $< -o  $@

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

