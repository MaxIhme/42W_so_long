/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:47:44 by mrehberg          #+#    #+#             */
/*   Updated: 2022/06/28 12:29:29 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long int	get_sign(int *n, int *neg)
{
	long int	number;

	number = *n;
	if (*n < 0)
	{
		*neg = 1;
		number = number * -1;
	}
	else
	{
		*neg = 0;
	}
	return (number);
}

static	int	count_digits(long n, int *neg)
{
	int	digits;

	if (*neg == 1)
		digits = 1;
	else
		digits = 0;
	while (n > 9)
	{
		digits++;
		n = n / 10;
	}
	digits++;
	return (digits);
}

static	void	fill_string(char *ptr, long number, int neg, int digits)
{
	int		i;
	int		sum_digits;

	i = 0;
	sum_digits = digits;
	if (neg == 1)
	{
		ptr[0] = '-';
		digits--;
	}
	while (i < digits)
	{
		ptr[sum_digits - 1 - i] = (int)(number % 10) + '0';
		number = number / 10;
		i++;
	}
	ptr[sum_digits] = 0;
}

/**
 * @brief converts int to alpha, allocates memory - don't forget to free
 * 
 * @param n 
 * @return ptr to memory with numeric chars - ends with \0
 */
char	*ft_itoa(int n)
{
	int			neg;
	char		*ptr;
	int			digits;
	long int	number;

	number = get_sign(&n, &neg);
	digits = count_digits(number, &neg);
	ptr = malloc(digits + 1);
	if (ptr == NULL)
		return (NULL);
	fill_string(ptr, number, neg, digits);
	return (ptr);
}
