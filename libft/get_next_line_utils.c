/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:21:33 by mrehberg          #+#    #+#             */
/*   Updated: 2022/06/14 14:26:44 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/**
*@brief check if fd (filedescriptor) and BUFFER_SIZE are valid.
*Initialize a.als, a.rr, a.eol, a.lc, a.line
*@param line allocate 1 Byte (\0) for a.line
*@param als (actual line size) of line is 1, because of \0 in line
*@param lc (loop condition) = 1 for while loop in geet_next_line
*@return line (pointer to alloc memory)
*/
char	*init_a(int fd, char *buf, struct s_line *a)
{
	if (read(fd, NULL, 0) || (fd > 900) || (BUFFER_SIZE <= 0))
		return (NULL);
	a -> als = 1;
	a -> rr = BUFFER_SIZE;
	a -> eol = BUFFER_SIZE;
	a -> line = malloc(sizeof(char) * 1);
	if (a -> line == NULL)
		return (NULL);
	a -> line[0] = 0;
	a -> lc = 1;
	buf[BUFFER_SIZE] = 0;
	return (a -> line);
}

/**
*@brief search end of line (eol) in buf till you hit \\n or \0 up to rr
*@param buf pointer to the buffer
*@param a > rr - char that were read() into buf
*@param a > nl - (next line) = 1 if it hits \\n
*@return position of \\n or \0 in buf
*/
int	search_eol(char *buf, struct s_line *a)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && i < a -> rr && buf[i])
	{
		i++;
	}
	if (buf[i] == '\n')
		a -> nl = 1;
	if (buf[i] == 0)
		a -> nl = 0;
	return (i);
}

/**
 * @brief str_add puts a.old + buf[till eol] + \\n if nessesary + \0 into a.line
 * 
 * @param old actual line
 * @param line new alloc memory to add buf to the line
 * @param eol (end of line) - position of \\n or \0 in buf
 * @param nl 1 if on buf[eol] is \\n - 0 if there is \0
 */
void	str_add(char *buf, struct s_line *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a -> old[i])
	{
		a -> line[i] = a -> old[i];
		i++;
	}
	while (j < a -> eol)
	{
		a -> line[i] = buf[j];
		i++;
		j++;
	}
	if (a -> nl == 1)
	{
		a -> line[i] = '\n';
		a -> line[i + 1] = 0;
	}
	if (a -> nl == 0)
		a -> line[i] = 0;
}

/**
 * @brief proc_line (process line) allocs memory for new line size (line + buf)
 * then call str_add to concateenate them + free(old)
 * 
 * @param old buffers pointer to line, at the end free(old)
 * @param nl (next line) is 1 if buf[eol] is \\n (allocate 1 Byte more) 
 * ... 0 if it's \0 
 * @return pointer (line) to new memory
 */
char	*proc_line(char *buf, struct s_line *a)
{
	a -> old = a -> line;
	if (a -> nl == 1)
		a -> line = malloc(sizeof(char) * (a -> als + 1));
	if (a -> nl == 0)
		a -> line = malloc(sizeof(char) * a -> als);
	if (a -> line == NULL)
		return (NULL);
	str_add(buf, a);
	free(a -> old);
	return (a -> line);
}
