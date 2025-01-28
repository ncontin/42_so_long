/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:16:33 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/28 11:16:53 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
