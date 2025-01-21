/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:10:39 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/21 11:36:17 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef SO_LONG_H
# define SO_LONG_H

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	// t_map	*map;
}			t_data;

#endif
