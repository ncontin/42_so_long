/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:58:27 by ncontin           #+#    #+#             */
/*   Updated: 2025/05/07 18:37:00 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	handle_open_error(t_data *data, char *map_path)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Error opening file\n", 2);
	free(map_path);
	free(data->map);
	free(data);
	exit(1);
}

static void	handle_malloc_path(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Memory allocation failed\n", 2);
	free(data->map);
	free(data);
	exit(1);
}

static void	handle_line(t_data *data, char *line, char *map_path, int fd)
{
	if (!line)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Error reading file\n", 2);
		free(map_path);
		free(data->map);
		free(data);
		close(fd);
		exit(1);
	}
}

void	read_map(char *arg, t_data *data, int fd)
{
	char	*map_path;
	char	*line;
	int		len;

	map_path = ft_strjoin(MAP_FOLDER, arg);
	if (!map_path)
		handle_malloc_path(data);
	len = ft_strlen(map_path);
	if (len <= 4 || ft_strncmp(map_path + (len - 4), ".ber", 4) != 0)
		handle_open_error(data, map_path);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		handle_open_error(data, map_path);
	line = get_next_line(fd);
	handle_line(data, line, map_path, fd);
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
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Error opening file\n", 2);
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
