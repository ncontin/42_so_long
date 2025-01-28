/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:51:12 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/28 11:51:45 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_shape(t_data *data)
{
	if (data->map->width == data->map->height)
	{
		free_data(data);
		ft_putstr_fd("Error\nThe map must be rectangular\n", 2);
		exit(1);
	}
}
