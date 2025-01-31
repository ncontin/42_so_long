/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:29 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/31 12:21:03 by ncontin          ###   ########.fr       */
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
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("The top wall must be closed\n", 2);
			exit(1);
		}
		j++;
	}
}

static void	check_bot_wall(t_data *data)
{
	int	j;

	j = 0;
	while (data->map->grid[data->map->height - 1][j] != '\n'
		&& data->map->grid[data->map->height - 1][j] != '\0')
	{
		if (data->map->grid[data->map->height - 1][j] != '1')
		{
			free_data(data);
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("The bottom wall must be closed\n", 2);
			exit(1);
		}
		j++;
	}
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
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("The left wall must be closed\n", 2);
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
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("The right wall must be closed\n", 2);
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
