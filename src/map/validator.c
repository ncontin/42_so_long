/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:58:49 by ncontin           #+#    #+#             */
/*   Updated: 2025/02/05 16:34:24 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	validate_map(t_data *data)
{
	check_map_size(data);
	check_map_shape(data);
	check_map_components(data);
	check_map_walls(data);
	check_map_path(data);
}
