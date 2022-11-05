/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:19:46 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/02 20:47:42 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief copies the char map to an int map where 1 is the border
 * 2 is the starting position and 3 is the exit and collectibles
 */
int**	copy_map(t_window *window, int **map_copy)
{
	int run_height;
	int	run_width;

	run_height = 0;
	map_copy = malloc(sizeof(int*) * window -> map_height);
	while (run_height < window -> map_height)
	{
		run_width = 0;
		map_copy[run_height] = malloc(sizeof(int) * window -> map_width);
		while (run_width < window -> map_width)
		{
			if (window -> map[run_height][run_width] == '1')
				map_copy[run_height][run_width] = 1;
			if (window -> map[run_height][run_width] == '0')
				map_copy[run_height][run_width] = 0;
			if (window -> map[run_height][run_width] == 'P')
				map_copy[run_height][run_width] = 2;
			if (window -> map[run_height][run_width] == 'C')
				map_copy[run_height][run_width] = 3;
			if (window -> map[run_height][run_width] == 'E')
				map_copy[run_height][run_width] = 4;
			run_width++;
		}
		run_height++;
	}
	return (map_copy);
}

void	show_copy_map(t_window *window, int **map_copy)
{
	int run_height;
	int	run_width;

	run_height = 0;
	while (run_height < window -> map_height)
	{
		run_width = 0;
		while (run_width < window -> map_width)
		{
			ft_printf("%d", map_copy[run_height][run_width]);
			run_width++;
		}
		ft_printf("\n");
		run_height++;
	}
	ft_printf("\n");
}

/**
 * @brief look up, down, left, right of act positon and change 0 to 2
 * @return number of changes, return -1 if found exit
 */
int	substitute_zeros(int **map_copy, int run_height, int run_width, t_window *window)
{
	int change;
	static int e_flag = 0;

	if (map_copy[run_height - 1][run_width] == 4 ||
		map_copy[run_height + 1][run_width] == 4 ||
		map_copy[run_height][run_width - 1] == 4 ||
		map_copy[run_height][run_width + 1] == 4)
		{
			if (e_flag == 0)
			{
				window -> count_c_e--;
				e_flag = 1;
			}

			//return (-1);
		}
	if (map_copy[run_height - 1][run_width] == 3 ||
		map_copy[run_height + 1][run_width] == 3 ||
		map_copy[run_height][run_width - 1] == 3 ||
		map_copy[run_height][run_width + 1] == 3)
		{
			window -> count_c_e--;
		}

	change = 0;
	if (map_copy[run_height - 1][run_width] == 0 ||
		map_copy[run_height - 1][run_width] == 3)
	{
		map_copy[run_height - 1][run_width] = 2;
		change++;
	}
	if (map_copy[run_height + 1][run_width] == 0 ||
		map_copy[run_height + 1][run_width] == 3)
	{
		map_copy[run_height + 1][run_width] = 2;
		change++;
	}
	if (map_copy[run_height][run_width - 1] == 0 ||
		map_copy[run_height][run_width - 1] == 3)
	{
		map_copy[run_height][run_width - 1] = 2;
		change++;
	}
	if (map_copy[run_height][run_width + 1] == 0 ||
		map_copy[run_height][run_width + 1] == 3)
	{
		map_copy[run_height][run_width + 1] = 2;
		change++;
	}
	//ft_printf("%d\n", window -> count_c_e);
	//show_copy_map(window, map_copy);
	return (change);
}

/**
 * @brief scan through the map as long as 0's will be changed to 2's
 * when every 0 is changes that is reachable then look for the exit
 * @param window 
 * @param map_copy 
 * @return int 
 */
int	scan_map_for_twos(t_window *window, int **map_copy)
{
	int run_height;
	int	run_width;
	int change;

	change = 0;
	run_height = 0;
	while (run_height < window -> map_height)
	{
		run_width = 0;
		while (run_width < window -> map_width)
		{
			if (map_copy[run_height][run_width] == 2 )//|| 
				//map_copy[run_height][run_width] == 3)
			{
				change += substitute_zeros(map_copy, run_height, run_width, window);
				
				//if (change == -1)
				if (window -> count_c_e == 0)
					return (-1);
			}
			run_width++;
		}
		run_height++;
	}
	return (change);
}

/**
 * @brief from the starting position P spread like a virus until you hit all C's and the exit
 * 
 * @param window 
 */
void	check_path(t_window *window)
{
	int	change;
	int **map_copy;

	map_copy = copy_map(window, map_copy);
	//show_copy_map(a, a_copy);

	change = 1;
	while (change != 0 && change != -1)
	{
		change = scan_map_for_twos(window, map_copy);
		//ft_printf("change: %d\n\n", change);
		//show_copy_map(window, map_copy);
	}
	int i = 0;
	while (i < window -> map_height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (change == 0)
		error(5);
	if (change == -1)
		ft_printf("yeah, found a path\n");
}