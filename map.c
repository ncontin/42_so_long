/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:45:51 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/24 16:15:39 by ncontin          ###   ########.fr       */
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
		free(data->map);
		free(data);
		free(map_path);
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
		free(map_path);
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
