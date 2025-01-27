/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:45:51 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/27 18:24:23 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *arg, t_data *data)
{
	int		fd;
	char	*map_path;
	char	*line;

	data->map->height = 0;
	map_path = ft_strjoin(MAP_FOLDER, arg);
	if (!map_path)
		return ;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nError opening file\n", 2);
		free(map_path);
		free(data->map);
		free(data);
		exit(1);
	}
	line = get_next_line(fd);
	data->map->width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->map->height++;
	}
	close(fd);
	free(map_path);
}

void	store_grid(char *arg, t_data *data)
{
	char	*map_path;
	int		i;
	int		fd;

	i = 0;
	map_path = ft_strjoin(MAP_FOLDER, arg);
	if (!map_path)
		return ;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nError opening file\n", 2);
		free(data->map);
		free(data);
		return ;
	}
	data->map->grid = malloc(sizeof(char *) * (data->map->height + 1));
	if (!data->map->grid)
		return ;
	data->map->grid[i] = get_next_line(fd);
	while (data->map->grid[i++])
		data->map->grid[i] = get_next_line(fd);
	close(fd);
	free(map_path);
}

void	check_map_elements(t_data *data)
{
	int	i;
	int	j;
	int	door;
	int	collectible;
	int	player;

	door = 0;
	collectible = 0;
	player = 0;
	i = 0;
	while (data->map->grid[i])
	{
		j = 0;
		while (data->map->grid[i][j])
		{
			if (data->map->grid[i][j] == 'E')
				door = 1;
			else if (data->map->grid[i][j] == 'C')
				collectible += 1;
			else if (data->map->grid[i][j] == 'P')
				player += 1;
			j++;
		}
		i++;
	}
	if (door != 1 || collectible < 1 || player != 1)
	{
		free_map(data);
		ft_putstr_fd("Error\nThe map is invalid\n", 2);
		exit(1);
	}
}

void	check_map_shape(t_data *data)
{
	if (data->map->width == data->map->height)
	{
		free_map(data);
		ft_putstr_fd("Error\nThe map must be rectangular\n", 2);
		exit(1);
	}
}

void	check_top_wall(t_data *data)
{
	int	j;

	j = 0;
	while (data->map->grid[0][j] != '\n')
	{
		if (data->map->grid[0][j] != '1')
		{
			free_map(data);
			ft_putstr_fd("Error\nThe top wall must be closed/surrounded by walls\n",
				2);
			exit(1);
		}
		j++;
	}
}
void	check_bot_wall(t_data *data)
{
	int	j;

	j = 0;
	while (data->map->grid[data->map->height - 1][j] != '\n')
	{
		if (data->map->grid[data->map->height - 1][j] != '1')
		{
			free_map(data);
			ft_putstr_fd("Error\nThe bottom wall must be closed/surrounded by walls\n",
				2);
			exit(1);
		}
		j++;
	}
	return ;
}

void	check_left_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		if (data->map->grid[i][0] != '1')
		{
			free_map(data);
			ft_putstr_fd("Error\nThe left wall must be closed/surrounded by walls\n",
				2);
			exit(1);
		}
		i++;
	}
}

void	check_right_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		if (data->map->grid[i][data->map->width - 1] != '1')
		{
			free_map(data);
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

void	find_player_pos(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_map *map, int player_x, int player_y)
{
	// if (player_x < 0 || player_y < 0 || player_y >= map->height
	// 	|| player_x >= map->width)
	// 	return ;
	if (map->grid[player_y][player_x] == '1'
		|| map->grid[player_y][player_x] == 'V')
		return ;
	ft_printf("Filling position [%d][%d] with V\n", player_x, player_y);
	map->grid[player_y][player_x] = 'V';
	flood_fill(map, player_x + 1, player_y);
	flood_fill(map, player_x - 1, player_y);
	flood_fill(map, player_x, player_y + 1);
	flood_fill(map, player_x, player_y - 1);
}

void	copy_map(t_map *map_copy, t_data *data)
{
	int	i;

	i = 0;
	// int		collectibles_found;
	// int		exit_found;
	map_copy->grid = malloc(sizeof(char *) * (data->map->height + 1));
	if (!map_copy->grid)
		return ;
	while (i < data->map->height)
	{
		map_copy->grid[i] = ft_strdup(data->map->grid[i]);
		i++;
	}
	map_copy->grid[i] = NULL;
}
void	check_map_path(t_data *data)
{
	t_map	*map_copy;
	int		i;

	map_copy = malloc(sizeof(t_map));
	if (!map_copy)
		return ;
	copy_map(map_copy, data);
	find_player_pos(map_copy);
	flood_fill(map_copy, map_copy->player_x, map_copy->player_y);
	i = 0;
	while (map_copy->grid[i])
	{
		ft_printf("copy: %s", map_copy->grid[i]);
		free(map_copy->grid[i]);
		i++;
	}
	free(map_copy->grid);
	free(map_copy);
}

void	validate_map(t_data *data)
{
	check_map_elements(data);
	check_map_shape(data);
	check_map_walls(data);
	check_map_path(data);
}
