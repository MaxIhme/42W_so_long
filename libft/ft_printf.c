/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:25:54 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/03 20:42:08 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_conversion(char str, va_list args, int count)
{
	if ((str == 'd')| (str == 'i'))
		count += print_decimal(va_arg(args, int));
	else if (str == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		count++;
	}
	else if (str == 's')
		count += print_string(va_arg(args, char *));
	else if (str == 'u')
		count += print_unsigned(va_arg(args, unsigned int));
	else if (str == 'x')
		count += print_hex(va_arg(args, unsigned int), 0);
	else if (str == 'X')
		count += print_hex(va_arg(args, unsigned int), 1);
	else if (str == 'p')
		count += print_ptr((unsigned long int)va_arg(args, void *));
	else if (str == '%')
	{
		ft_putchar_fd(str, 1);
		count++;
		//ft_putchar_fd(str[1], 1);

	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		count;

	va_start(args, str);
	count = 0;
	
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count = read_conversion(*str, args, count);
		}
		else
		{
			ft_putchar_fd(*str,1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
