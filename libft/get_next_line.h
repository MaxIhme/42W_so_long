/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:06:58 by mrehberg          #+#    #+#             */
/*   Updated: 2022/06/14 10:57:53 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>

/**
 * @brief struct with different variables for calculation
 * 
 * @param line points to the Memory were the hole line is saved. 
 * Will be returned from get_next_line.
 * @param old buffer pointer to the old line and for free()
 * @param als actual line size (of line)
 * @param eol end of line - Position of \\n or \0 in buf
 * @param rr read return (holds the value that read func returns) 
 * (only set by read() function and in init_a for initialisation)
 * @param nl next line - Flag if sign is '\n' or '\0' (only set in search_eol)
 * @param lc loop condition for while loop in get_next_line
 */
struct s_line
{
	char	*line;
	char	*old;
	int		als;
	int		eol;
	int		rr;
	int		nl;
	int		lc;
};

char	*get_next_line(int fd);
char	*init_a(int fd, char *buf, struct s_line *a);
size_t	ft_strlen(char *str);
int		search_eol(char *buf, struct s_line *a);
void	set_lc_phase(struct s_line *a, char *buf, int *phase);
void	proc_buf(char *buf, struct s_line *a);
char	*proc_line(char *buf, struct s_line *a);
void	str_add(char *buf, struct s_line *a);

#endif
