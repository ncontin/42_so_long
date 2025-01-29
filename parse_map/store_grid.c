/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:17:38 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/29 12:48:44 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
