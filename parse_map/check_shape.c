/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/31 12:47:16 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handle_error(t_data *data, char *map_path)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("The map must be rectangular\n", 2);
	free(map_path);
	free(data->map);
	free(data);
	exit(1);
}

void	check_map_shape(t_data *data, char *line, char *map_path)
{
	if (line[ft_strlen(line) - 1] == '\n')
	{
		if (data->map->width != ((int)ft_strlen(line) - 1))
		{
			ft_putstr_fd("shape error\n", 2);
			ft_printf("width: %d", data->map->width);
			handle_error(data, map_path);
		}
	}
	else
	{
		if (data->map->width != (int)ft_strlen(line))
		{
			ft_putstr_fd("last line\n", 1);
			ft_putstr_fd("shape error\n", 2);
			ft_printf("width: %d", data->map->width);
			handle_error(data, map_path);
		}
	}
}

// void	check_map_shape(t_data *data, char *line, char *map_path)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	ft_printf("width: %s, grid ", data->map->width);
// 	while (data->map->grid[i][j] != '\n')
// 	{
// 		j = 0;
// 		if (data->map->grid[0][j] != '1')
// 		{
// 			free_data(data);
// 			ft_putstr_fd("Error\n", 2);
// 			ft_putstr_fd("The top wall must be closed\n", 2);
// 			exit(1);
// 		}
// 		j++;
// 	}
// }
