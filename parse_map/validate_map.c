/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:53:48 by ncontin           #+#    #+#             */
/*   Updated: 2025/01/28 11:55:31 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_map(t_data *data)
{
	check_map_components(data);
	check_map_shape(data);
	check_map_walls(data);
	check_map_path(data);
}
