/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:08:31 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/17 13:47:58 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	size_of_string(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i + 1);
}

char	*ft_strdup(const char *str)
{
	int		size;
	char	*ptr;

	size = size_of_string(str);
	ptr = ft_calloc(size, 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, str, size);
	return (ptr);
}
