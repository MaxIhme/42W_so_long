/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:05:24 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/23 18:43:42 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// set val len times in sentence
void	*ft_memset(void *sentence, int val, size_t len)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *) sentence;
	i = 0;
	while (i < len)
	{
		dest[i] = (unsigned char) val;
		i++;
	}
	return (sentence);
}
