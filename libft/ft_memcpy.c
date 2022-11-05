/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:06:58 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/23 17:56:44 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t len)
{
	size_t	i;
	char	*dest;
	char	*src;

	if (destination == NULL && source == NULL)
		return (NULL);
	dest = (char *) destination;
	src = (char *) source;
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
