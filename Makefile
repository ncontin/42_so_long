# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 13:12:10 by ncontin           #+#    #+#              #
#    Updated: 2025/01/30 10:57:10 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	so_long.c\
		open_window.c\
		parse_map/check_path.c\
		parse_map/check_shape.c\
		parse_map/check_walls.c\
		parse_map/components.c\
		parse_map/read_map.c\
		parse_map/store_grid.c\
		parse_map/validate_map.c\
		handle_textures/draw_textures.c\
		handle_textures/load_textures.c\
		cleanup.c\
		game_logic/collect_keys.c\
		game_logic/end_game.c\
		game_logic/player_move.c\
		libs/gnl/get_next_line.c\
		libs/gnl/get_next_line_utils.c\

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Llibs/mlx -lmlx -lX11 -lXext -lm
RM = rm -f

OBJ = $(SRC:.c=.o)
INCLUDES = -I./libs/libft -I./libs/ft_printf -I./libs/gnl -I./libs/mlx
LIBS = libs/libft/libft.a libs/ft_printf/libftprintf.a

all: $(NAME)

$(NAME):$(OBJ)
	make all -C libs/libft
	make all -C libs/ft_printf
	$(CC) $(OBJ) $(MLX_FLAGS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx_linux -O3 -c $< -o  $@

clean:
	$(RM) $(OBJ)
	make clean -C libs/libft
	make clean -C libs/ft_printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C libs/libft
	make fclean -C libs/ft_printf

re: fclean all

.PHONY: all clean fclean re mlx

