# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 13:12:10 by ncontin           #+#    #+#              #
#    Updated: 2025/02/05 15:47:51 by ncontin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	so_long.c\
		$(SRC_CORE)\
		$(SRC_GAME)\
		$(SRC_MAP)\
		$(SRC_MAP_CHECKS)\
		libs/gnl/get_next_line.c\
		libs/gnl/get_next_line_utils.c\

SRC_CORE = src/core/window.c src/core/init.c src/core/cleanup.c
SRC_GAME = src/game/player.c src/game/collect.c src/game/end.c
SRC_MAP = src/map/parser.c src/map/validator.c src/map/render.c src/map/finder.c
SRC_MAP_CHECKS = src/map/checks/check_components.c src/map/checks/check_path.c src/map/checks/check_shape.c src/map/checks/check_size.c src/map/checks/check_walls.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
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

