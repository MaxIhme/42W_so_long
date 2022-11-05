/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:48:43 by mrehberg          #+#    #+#             */
/*   Updated: 2022/06/19 21:40:53 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief looks byte for byte after c in s up to n bytes. If found, 
 * returns Adress (Pointer) of the byte. otherwise returns NULL. 
 * Be carefull with integers.
 * 
 * @param s can be a pointer to a string
 * @param c can be a char as an int value
 * @param n is size_t
 * @return pointer to found byte or else NULL
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*st;
	size_t			i;

	chr = (unsigned char)c;
	st = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (st[i] == chr)
		{
			return (&st[i]);
		}
		i++;
	}
	return (NULL);
}
