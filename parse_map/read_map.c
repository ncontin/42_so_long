/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:16:33 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/03 16:58:16 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	free_data(data);
	exit(1);
}

void	read_map(char *arg, t_data *data, int fd)
{
	char	*map_path;
	char	*line;
	int		len;

	data->map->height = 0;
	map_path = ft_strjoin(MAP_FOLDER, arg);
	if (!map_path)
		handle_malloc_path(data);
	len = ft_strlen(map_path);
	if (ft_strncmp(map_path + (len - 4), ".ber", 4) != 0)
		handle_open_error(data, map_path);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		handle_open_error(data, map_path);
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
