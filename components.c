/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:18:46 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/04 18:43:50 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_component_pos(t_map *map, int y, int x, char component)
{
	if (map->grid[y][x] == component)
	{
		if (component == 'P')
		{
			map->player_x = x;
			map->player_y = y;
		}
		else if (component == 'E')
		{
			map->exit_x = x;
			map->exit_y = y;
		}
		else if (component == 'C')
			map->collectibles++;
	}
}

void	find_components(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			get_component_pos(map, y, x, 'P');
			get_component_pos(map, y, x, 'E');
			get_component_pos(map, y, x, 'C');
			x++;
		}
		y++;
	}
}

void	check_result(t_data *data, int door, int collectible, int player)
{
	if (door != 1 || collectible < 1 || player != 1)
	{
		free_data(data);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The map is invalid\n", 2);
		exit(1);
	}
}
void	check_char(char c, int *door, int *collectible, int *player)
{
	if (c != 'E' && c != 'P' && c != '0' && c != 'C' && c != '1')
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Unkown character found\n", 2);
		exit(1);
	}
	if (c == 'E')
		(*door) += 1;
	else if (c == 'C')
		(*collectible) += 1;
	else if (c == 'P')
		(*player) += 1;
}

void	check_map_components(t_data *data)
{
	int	y;
	int	x;
	int	door;
	int	collectible;
	int	player;

	door = 0;
	collectible = 0;
	player = 0;
	y = 0;
	while (data->map->grid[y])
	{
		x = 0;
		while (x < data->map->width)
		{
			check_char(data->map->grid[y][x], &door, &collectible, &player);
			x++;
		}
		y++;
	}
	check_result(data, door, collectible, player);
}
