/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:45:51 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/27 12:39:05 by ncontin          ###   ########.fr       */
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
		perror("Error opening file");
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
		perror("Error opening file");
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
		ft_putstr_fd("The map is invalid\n", 2);
		exit(1);
	}
}

void	check_map_shape(t_data *data)
{
	if (data->map->width == data->map->height)
	{
		free_map(data);
		ft_putstr_fd("The map must be rectangular\n", 2);
		exit(1);
	}
}
// void	check_top_wall(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (data->map->grid[0][j])
// 	{
// 		if (data->map->grid[0][j] != '1')
// 		{
// 			free_map(data);
// 			ft_putstr_fd("The map must be closed/surrounded by walls.\n", 2);
// 			exit(1);
// 		}
// 		j++;
// 	}
// }
void	check_map_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map->grid[0][j])
	{
		if (data->map->grid[0][j] != '1')
		{
			free_map(data);
			ft_putstr_fd("The map must be closed/surrounded by walls.\n", 2);
			exit(1);
		}
		j++;
	}
	while (data->map->grid[data->map->height][j])
	{
		if (data->map->grid[0][j] != '1')
		{
			free_map(data);
			ft_putstr_fd("The map must be closed/surrounded by walls.\n", 2);
			exit(1);
		}
		j++;
	}
	while (data->map->grid[i][0])
	{
		if (data->map->grid[i][0] != '1')
		{
			free_map(data);
			ft_putstr_fd("The map must be closed/surrounded by walls.\n", 2);
			exit(1);
		}
		i++;
	}
	while (data->map->grid[i][data->map->width])
	{
		if (data->map->grid[i][data->map->width] != '1')
		{
			free_map(data);
			ft_putstr_fd("The map must be closed/surrounded by walls.\n", 2);
			exit(1);
		}
		i++;
	}
}

void	validate_map(t_data *data)
{
	check_map_elements(data);
	check_map_shape(data);
	check_map_walls(data);
}
