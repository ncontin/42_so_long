/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:47:24 by ncontin           #+#    #+#             */
/*   Updated: 2024/11/04 10:44:54 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_ptr(size_t nbr)
{
	int	counter;
	int	rem;

	counter = 0;
	if (nbr >= 16)
		counter += ft_print_hex_ptr(nbr / 16);
	rem = nbr % 16;
	if (rem < 10)
		ft_print_char(rem + '0');
	else
		ft_print_char(rem + 87);
	counter++;
	return (counter);
}

int	ft_print_ptr(void *n)
{
	int		counter;
	size_t	nbr;

	nbr = (size_t)n;
	counter = 2;
	if (n == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	counter += ft_print_hex_ptr(nbr);
	return (counter);
}
