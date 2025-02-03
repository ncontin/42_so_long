/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/03 13:42:13 by ncontin          ###   ########.fr       */
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
static void	handle_error_new(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("The map must be rectangular\n", 2);
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

void	check_map_shape_new(t_data *data)
{
	int	y;
	int	len;

	y = 0;
	while (data->map->grid[y])
	{
		len = ft_strlen(data->map->grid[y]);
		if (data->map->grid[y][len - 1] == '\n')
			len--;
		if (data->map->grid[y][len] == '\0')
			len++;
		if (len != data->map->width)
		{
			ft_printf("Error line %d: expected width %d, got %d\n", y + 1,
				data->map->width, len);
			handle_error_new(data);
		}
		y++;
	}
}
