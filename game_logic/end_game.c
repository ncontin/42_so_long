/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:51:48 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/29 11:52:35 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_data *data)
{
	int	x;
	int	y;

	x = data->map->player_x;
	y = data->map->player_y;
	if (data->map->grid[y][x] == 'E' && data->map->collected == 1)
	{
		ft_printf("Congratulations, you finished the game with %d moves\n",
			data->move_count);
		cleanup(data);
		exit(0);
	}
}
