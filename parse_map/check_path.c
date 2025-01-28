/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:56 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/28 12:02:13 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(t_map *map, int player_x, int player_y)
{
	if (map->grid[player_y][player_x] == '1'
		|| map->grid[player_y][player_x] == 'V')
		return ;
	if (map->grid[player_y][player_x] == 'C')
		map->collectibles--;
	map->grid[player_y][player_x] = 'V';
	flood_fill(map, player_x + 1, player_y);
	flood_fill(map, player_x - 1, player_y);
	flood_fill(map, player_x, player_y + 1);
	flood_fill(map, player_x, player_y - 1);
}

static void	copy_map(t_map *map_copy, t_data *data)
{
	int	i;

	i = 0;
	map_copy->grid = malloc(sizeof(char *) * (data->map->height + 1));
	if (!map_copy->grid)
		return ;
	while (i < data->map->height)
	{
		map_copy->grid[i] = ft_strdup(data->map->grid[i]);
		i++;
	}
	map_copy->grid[i] = NULL;
	map_copy->collectibles = 0;
	map_copy->collected = 0;
}

void	check_map_path(t_data *data)
{
	t_map	*map_copy;
	int		exit_found;

	exit_found = 0;
	map_copy = malloc(sizeof(t_map));
	if (!map_copy)
		return ;
	copy_map(map_copy, data);
	find_components(map_copy);
	flood_fill(map_copy, map_copy->player_x, map_copy->player_y);
	if (map_copy->grid[map_copy->exit_y][map_copy->exit_x] == 'V')
		exit_found = 1;
	if (map_copy->collectibles == 0)
		map_copy->collected = 1;
	if (exit_found != 1 || map_copy->collected != 1)
	{
		ft_putstr_fd("Error\nIvalid path in the map\n", 2);
		free_data(data);
		free_map(map_copy);
		exit(1);
	}
	free_map(map_copy);
}
