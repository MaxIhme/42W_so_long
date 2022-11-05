/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:15:26 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/03 21:49:16 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int character)
{
	if (character >= 48 && character <= 57)
		return (1);
	if (character >= 65 && character <= 90)
		return (1);
	if (character >= 97 && character <= 122)
		return (1);
	return (0);
}
