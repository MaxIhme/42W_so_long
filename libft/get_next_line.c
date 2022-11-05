/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:25:33 by mrehberg          #+#    #+#             */
/*   Updated: 2022/06/27 10:47:44 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *sentence, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		sentence[i] = 0;
		i++;
	}
}

/**
 * @brief proc_buf (process buffer) copies all that comes after \\n 
 * to the beginning of buf + \0 at the end
 * 
 * @param rr (read return) how many bytes were read into buf
 * rr < BUFFER_SIZE - end of file - put \0 behind last char
 * @param nl (next line) - found \\n in buf
 */
void	proc_buf(char *buf, struct s_line *a)
{
	int	i;
	int	j;

	if (a -> rr < BUFFER_SIZE)
		buf[a -> rr] = 0;
	if (a -> nl == 1)
	{
		i = a -> eol + 1;
		j = 0;
		while (buf[i])
		{
			buf[j] = buf[i];
			i++;
			j++;
		}
	}	
	if (a -> nl == 0)
		j = 0;
	buf[j] = 0;
}

/**
 * @brief Set the lc (loop condition) and phase (state)
 *  
 * @param lc (loop condition) set to 0 when:
 * - a rest remains in buf
 * - or nothing in buf and end of file
 * - or last char in buf is \\n
 * @param phase  * _ phase 1: read from file into buf
 * _ phase 2: don't read, copy rest from buf to line
 * _ phase 3: not used anymore
 * _ phase 4: like 2, but read() has come to the end of the file
 * 
 */
void	set_lc_phase(struct s_line *a, char *buf, int *phase)
{
	if (buf[0])
		a -> lc = 0;
	if (buf[0] == 0 && a -> rr < BUFFER_SIZE)
		a -> lc = 0;
	if (a -> nl == 1)
		a -> lc = 0;
	a -> eol = search_eol(buf, a);
	if (a -> rr == BUFFER_SIZE)
	{
		if (!buf[0])
			*phase = 1;
		if (buf[0])
			*phase = 2;
	}
	if (a -> rr < BUFFER_SIZE)
	{
		if (!buf[0])
			*phase = 1;
		if (buf[0])
			*phase = 4;
	}
}

void	after_loop(struct s_line *a)
{
	if (a -> line[0] == 0 && a -> rr == 0)
	{
		free(a -> line);
		a -> line = NULL;
	}
}

/**
 * @brief reads a line from a fd and returns a pointer to that
 * 
 * @param a different variables in a struct,
 * see comments of struct s_line in get_next_line.h .
 * initializes + reads from fd into buf + copies from buf in line 
 * + processes buf + set loop condition and phase + if necessary free(line) 
 * @param buf Buffer of size BUFFER_SIZE + 1 (\0)
 * @param phase diffeerent states of the function, 
 * see comments of set_lc_phase
 * @param 
 * @return Pointer to allocated memory, free() after use!
 */
char	*get_next_line(int fd)
{
	struct s_line	a;
	static char		buf[BUFFER_SIZE + 1];
	static int		phase = 1;

	if (!init_a(fd, buf, &a))
		return (NULL);
	while (a.lc)
	{
		if (phase == 1)
		{
			ft_bzero(buf, BUFFER_SIZE);
			a.rr = read(fd, buf, BUFFER_SIZE);
		}
		a.eol = search_eol(buf, &a);
		a.als += a.eol;
		if (a.rr > 0)
			if (!proc_line(buf, &a))
				return (NULL);
		if (a.rr > 0)
			proc_buf(buf, &a);
		set_lc_phase(&a, buf, &phase);
	}
	after_loop(&a);
	return (a.line);
}
