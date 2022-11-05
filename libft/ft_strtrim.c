/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:39:41 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/28 12:03:35 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// does not change set
static	int	char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// start will be first char in the word, 
// end will be the last char in the last word
// if only separation signs end < start (handled in ft_strtrim)
// does not change str or set
static	void	find_se(char const *str, char const *set, int *start, int *end)
{
	int	i;

	i = 0;
	while (str[i] && char_in_set(str[i], set))
	{
		i++;
	}
	*start = i;
	i = (ft_strlen((char *)str) - 1);
	while (i && char_in_set(str[i], set))
	{
		i--;
	}
	*end = i;
}

// does not change s1 or set
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	if (ft_strlen((char *)s1) == 0)
	{
		ptr = ft_calloc(1, 1);
		return (ptr);
	}
	find_se(s1, set, &start, &end);
	if (end - start < 0)
	{
		ptr = ft_calloc(1, 1);
		return (ptr);
	}
	ptr = malloc(1 * (end - start + 2));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], (end - start + 2));
	return (ptr);
}
