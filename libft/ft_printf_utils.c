/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:44:58 by mrehberg          #+#    #+#             */
/*   Updated: 2022/06/28 13:03:21 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(int num)
{
	char 	*alpha;
	int		count;

	alpha = ft_itoa(num);
	count = ft_strlen(alpha);
	ft_putstr_fd(alpha, 1);
	free(alpha);
	return (count);
}

int	print_string(char *str)
{
	int count;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (count);
}

int	print_unsigned(unsigned int num)
{
	int		count;
	unsigned int	num_single;

	count = 0;
	if (num > 9)
		count += print_unsigned(num / 10);
	num_single = num%10 + '0';
	count += write(1, &num_single, 1);
	return (count);
}

int	print_hex(unsigned int num, int flag)
{
	int count;
	int	act;
	char hex;

	count = 0;
	if (num > 15)
		count += print_hex(num/16, flag);
	act = num%16;
	if (flag == 0)
		hex = "0123456789abcdef"[act];
	else
		hex = "0123456789ABCDEF"[act];
	count++;
	ft_putchar_fd(hex, 1);
	return (count);
}

int	print_ptr(unsigned long int num)
{
	int count;
	unsigned long int	act;
	char hex;

	count = 0;
	if (num > 15)
		count += print_ptr(num/16);
	if (count == 0)
	{
		ft_putstr_fd("0x", 1);
		count += 2;
	}
	act = num%16;
	hex = "0123456789abcdef"[act];
	count++;
	ft_putchar_fd(hex, 1);
	return (count);
}
