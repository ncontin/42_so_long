# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 13:12:10 by ncontin           #+#    #+#              #
#    Updated: 2025/02/05 12:52:20 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	so_long.c\
		open_window.c\
		cleanup.c\
		parse_map/check_path.c\
		parse_map/check_components.c\
		parse_map/check_size.c\
		parse_map/check_shape.c\
		parse_map/check_walls.c\
		parse_map/read_map.c\
		parse_map/store_grid.c\
		parse_map/validate_map.c\
		components/draw_map.c\
		components/load_textures.c\
		game_logic/collect_keys.c\
		game_logic/end_game.c\
		game_logic/player_move.c\
		libs/gnl/get_next_line.c\
		libs/gnl/get_next_line_utils.c\

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Llibs/mlx -lmlx -lX11 -lXext -lm
RM = rm -f
INCLUDES = -I./libs/libft -I./libs/ft_printf -I./libs/gnl -I./libs/mlx
LIBS = libs/libft/libft.a libs/ft_printf/libftprintf.a

all: $(NAME)

$(NAME):$(OBJ)
	make all -C libs/libft
	make all -C libs/ft_printf
	make -C libs/mlx
	$(CC) $(OBJ) $(MLX_FLAGS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C libs/libft
	make clean -C libs/ft_printf
	make clean -C libs/mlx

fclean: clean
	$(RM) $(NAME)
	make fclean -C libs/libft
	make fclean -C libs/ft_printf

re: fclean all

.PHONY: all clean fclean re

