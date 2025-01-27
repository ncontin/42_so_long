/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:10:39 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/27 12:36:02 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAP_FOLDER "maps/"
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

# define BG 0
# define WALL 1
# define EXIT 2
# define PLAYER 3
# define KEY 4

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		tile_size;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		exit_x;
	int		exit_y;
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	int		move_count;
	t_map	*map;
}			t_data;

void		cleanup(t_data *data);
void		free_grid(t_map *map);
void		read_map(char *arg, t_data *data);
void		store_grid(char *arg, t_data *data);
void		move_player_left(int key, t_data *data);
void		move_player_up(int key, t_data *data);
void		move_player_right(int key, t_data *data);
void		move_player_down(int key, t_data *data);
void		load_textures(t_data *data);
void		draw_wall(t_data *data, int y, int x, char c);
void		draw_bg(t_data *data, int y, int x, char c);
void		draw_exit(t_data *data, int y, int x, char c);
void		draw_player(t_data *data, int y, int x, char c);
void		draw_key(t_data *data, int y, int x, char c);
void		draw_map(t_data *data);
int			get_window_height(t_map *map);
int			get_window_width(t_map *map);
void		validate_map(t_data *data);
void		free_map(t_data *data);

#endif
