/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:29 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/28 11:56:32 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_top_wall(t_data *data)
{
	int	j;

	j = 0;
	while (data->map->grid[0][j] != '\n')
	{
		if (data->map->grid[0][j] != '1')
		{
			free_data(data);
			ft_putstr_fd("Error\nThe top wall must be closed/surrounded by walls\n",
				2);
			exit(1);
		}
		j++;
	}
}
static void	check_bot_wall(t_data *data)
{
	int	j;

	j = 0;
	while (data->map->grid[data->map->height - 1][j] != '\n')
	{
		if (data->map->grid[data->map->height - 1][j] != '1')
		{
			free_data(data);
			ft_putstr_fd("Error\nThe bottom wall must be closed/surrounded by walls\n",
				2);
			exit(1);
		}
		j++;
	}
	return ;
}

static void	check_left_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		if (data->map->grid[i][0] != '1')
		{
			free_data(data);
			ft_putstr_fd("Error\nThe left wall must be closed/surrounded by walls\n",
				2);
			exit(1);
		}
		i++;
	}
}

static void	check_right_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		if (data->map->grid[i][data->map->width - 1] != '1')
		{
			free_data(data);
			ft_putstr_fd("Error\nThe right must be closed/surrounded by walls\n",
				2);
			exit(1);
		}
		i++;
	}
}

void	check_map_walls(t_data *data)
{
	check_top_wall(data);
	check_bot_wall(data);
	check_left_wall(data);
	check_right_wall(data);
}
