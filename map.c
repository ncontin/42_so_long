/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:45:51 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/23 16:54:14 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *arg, t_map *map)
{
	int		fd;
	char	*map_path;
	char	*line;

	map->height = 0;
	map_path = ft_strjoin(MAP_FOLDER, arg);
	if (!map_path)
		return ;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		free(map_path);
		return ;
	}
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->height++;
	}
	close(fd);
	free(map_path);
}

void	store_grid(char *arg, t_map *map)
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
		free(map_path);
		return ;
	}
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return ;
	map->grid[i] = get_next_line(fd);
	while (map->grid[i++])
		map->grid[i] = get_next_line(fd);
	close(fd);
	free(map_path);
}
