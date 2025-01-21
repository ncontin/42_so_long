/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontin <ncontin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:52:31 by ncontin           #+#    #+#             */
/*   Updated: 2024/11/08 12:19:53 by ncontin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(const char *format, va_list args, int *i)
{
	int	counter;

	counter = 0;
	if (format[*i] == 'c')
		counter += ft_print_char(va_arg(args, int));
	else if (format[*i] == '%')
	{
		ft_print_char('%');
		counter++;
	}
	else if (format[*i] == 's')
		counter += ft_print_str(va_arg(args, char *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		counter += ft_print_nbr(va_arg(args, int));
	else if (format[*i] == 'u')
		counter += ft_print_uns(va_arg(args, unsigned int));
	else if (format[*i] == 'x' || format[*i] == 'X')
		counter += ft_print_hex(va_arg(args, unsigned int), format[*i]);
	else if (format[*i] == 'p')
		counter += ft_print_ptr(va_arg(args, void *));
	(*i)++;
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			counter += handle_format(format, args, &i);
		}
		else
		{
			ft_print_char(format[i]);
			counter++;
			i++;
		}
	}
	va_end(args);
	return (counter);
}
