/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:16:33 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/30 17:09:11 by ncontin          ###   ########.fr       */
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

void	read_map(char *arg, t_data *data)
{
	int		fd;
	char	*map_path;
	char	*line;
	int		ext;

	data->map->height = 0;
	map_path = ft_strjoin(MAP_FOLDER, arg);
	ext = ft_strlen(map_path);
	if (ft_strncmp(map_path + (ext - 4), ".ber", 4) != 0)
		handle_open_error(data, map_path);
	if (!map_path)
		return ;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		handle_open_error(data, map_path);
	line = get_next_line(fd);
	data->map->width = (int)ft_strlen(line) - 1;
	while (line)
	{
		// if (line[ft_strlen(line) - 1] == '\n')
		// {
		// 	if (data->map->width != ((int)ft_strlen(line) - 1))
		// 	{
		// 		ft_putstr_fd("shape error\n", 2);
		// 		ft_printf("width: %d", data->map->width);
		// 		// handle_open_error(data, map_path);
		// 	}
		// }
		// else if (data->map->width != ((int)ft_strlen(line)))
		// {
		// 	ft_putstr_fd("this should be the last line\n", 1);
		// 	ft_putstr_fd("shape error\n", 2);
		// 	ft_printf("width: %d", data->map->width);
		// 	// handle_open_error(data, map_path);
		// }
		free(line);
		line = get_next_line(fd);
		data->map->height++;
	}
	close(fd);
	free(map_path);
}
