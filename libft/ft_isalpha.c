/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:00:46 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/03 21:47:06 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// only takes one character as integer

int	ft_isalpha(int character)
{
	if (character >= 65 && character <= 90)
		return (1);
	if (character >= 97 && character <= 122)
		return (1);
	return (0);
}
