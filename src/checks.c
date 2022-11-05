/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:35:55 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/03 19:18:32 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd)
{
	char *line;
	int lines;
	
	lines = 0;
	while(line)
	{
		line = get_next_line(fd);
		free(line);
		lines ++;
	}
	lines--;
	return (lines);
}

/**
 * @brief 
 * 
 * @param argv 
 * @return char** (is allocated memory, don't forget to free)
 */
void	init_map(char *path, t_window *window)
{
	int		fd;
	char 	*line;
	int		run_line;

	run_line = 0;
	fd = open(path, O_RDONLY);
	window -> map_height = count_lines(fd);
	close(fd);
	window -> map = malloc((sizeof(char*)) * window -> map_height);
	fd = open(path, O_RDONLY);
	while(run_line < window -> map_height)
	{
		line = get_next_line(fd);
		window -> map[run_line] = line;
		run_line++;
	}
}

int	check_char(t_window *window)
{
	int run_height;
	int run_width;
	
	run_height = 0;
	while(run_height < window -> map_height)
	{
		run_width = 0;
		while(window -> map[run_height][run_width])
		{
			if (!(window -> map[run_height][run_width] == '1' ||
			window -> map[run_height][run_width] == '0' ||
			window -> map[run_height][run_width] == 'C' ||
			window -> map[run_height][run_width] == 'E' ||
			window -> map[run_height][run_width] == 'P'))
				error(1);
			if (window -> map[run_height][run_width] == 'P')
				{
					window -> player_pos_x = run_width;
					window -> player_pos_y = run_height;
				}
			run_width++;
		}
		run_height++;
	}
}

int count_width(t_window *window)
{
	int i;

	i = 0;
	while(window -> map[0][i])
	{
		i++;
	}
	window -> map_width = i;
}

int check_map(t_window *window)
{
	count_width(window);
	check_char(window);
	check_border(window);
	check_P_E_C(window);
	check_rectangularity(window);
	check_path(window);
	return (1); 
}
