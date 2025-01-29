/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:56:56 by ncontin           #+#    #+#             */
/*   Updated: 2024/11/04 10:45:01 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char hex_case)
{
	int	counter;
	int	rem;

	counter = 0;
	if (n >= 16)
		counter += ft_print_hex(n / 16, hex_case);
	rem = (n % 16);
	if (rem < 10)
		ft_print_char(rem + '0');
	else
	{
		if (hex_case == 'X')
			ft_print_char(rem + 55);
		else if (hex_case == 'x')
			ft_print_char(rem + 87);
	}
	counter++;
	return (counter);
}
