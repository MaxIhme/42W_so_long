/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:13:12 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/03 21:27:32 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	count;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	count = 0;
	if (d > s)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else if (s > d)
	{
		while (count < len)
		{
			d[count] = s[count];
			count++;
		}
	}
	return (dest);
}
