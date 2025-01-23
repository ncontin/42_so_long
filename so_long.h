/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:10:39 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/23 10:27:31 by ncontin          ###   ########.fr       */
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
	// void	*background;
	t_map	*map;
}			t_data;

#endif
