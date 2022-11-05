/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:54:55 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/23 17:58:54 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	fill_str(char *ptr, const char *str, int run, int end)
{
	while (run < end)
	{
		ptr[run] = (char)str[run];
		run++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*ptr;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	a = ft_strlen((char *)s1);
	b = ft_strlen((char *)s2);
	ptr = malloc(a + b + 1);
	if (ptr == NULL)
		return (NULL);
	fill_str(ptr, s1, i, a);
	while (i < b)
	{
		ptr[a + i] = (char)s2[i];
		i++;
	}
	ptr[a + b] = '\0';
	return (ptr);
}
