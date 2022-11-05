/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:04:38 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/26 11:58:50 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns pointer to allocated memmory of size count * size with 0's
void	*ft_calloc(int count, int size)
{
	char	*ret;
	size_t	i;
	size_t	memory;

	if (count < 0 || size < 0)
		return (NULL);
	memory = size * count;
	i = 0;
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	while (i < memory)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}
