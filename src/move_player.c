/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:59:45 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/01 18:36:22 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief 13 = w keycode
 * 0 = a
 * 1 = s
 * 2 = d
 * 53 = esc
 * 126 = arrow up
 * 123 = arrow left
 * 125 = arrow down
 * 124 = arrow right
 * 
 * @param key 
 * @param param 
 * @return int 
 */
int	key_event(int key, t_window *window)
{
	if (key == ESC)
	{
		//exit(0);
		close_game(window);

	}
	// davor alle allocs freen
	// if (key == W)
	// 	move_up();
	// if (key == A)
	// 	move_left();
	if (key == S)
		move_down(window);
	if (key == W)
		move_up(window);
	if (key == A)
		move_left(window);
	if (key == D)
		move_right(window);
	// if (key == D)
	// 	move_right();	
	return (0);
}

void	move_down(t_window *window)
{
	if (window -> map[window -> player_pos_y + 1][window -> player_pos_x] == '0' ||
		window -> map[window -> player_pos_y + 1][window -> player_pos_x] == 'C')
	{
		window -> map[window -> player_pos_y][window -> player_pos_x] = '0';
		window -> map[window -> player_pos_y + 1][window -> player_pos_x] = 'P';
		window -> player_pos_y = window -> player_pos_y + 1;
		draw_window(window);
	}
	else if (window -> map[window -> player_pos_y + 1][window -> player_pos_x] == 'E' &&
		is_c_in_map(window) == 0)
		{
			ft_printf("You are the Flunkyball champion\n");
			close_game(window);		
		}
}

void	move_up(t_window *window)
{
	if (window -> map[window -> player_pos_y - 1][window -> player_pos_x] == '0' ||
		window -> map[window -> player_pos_y - 1][window -> player_pos_x] == 'C')
	{
		window -> map[window -> player_pos_y][window -> player_pos_x] = '0';
		window -> map[window -> player_pos_y - 1][window -> player_pos_x] = 'P';
		window -> player_pos_y = window -> player_pos_y - 1;
		draw_window(window);
	}
	else if (window -> map[window -> player_pos_y - 1][window -> player_pos_x] == 'E' &&
		is_c_in_map(window) == 0)
		{
			ft_printf("You are the Flunkyball champion\n");
			close_game(window);		
		}
}

void	move_left(t_window *window)
{
	if (window -> map[window -> player_pos_y][window -> player_pos_x - 1] == '0' ||
		window -> map[window -> player_pos_y][window -> player_pos_x - 1] == 'C')
	{
		window -> map[window -> player_pos_y][window -> player_pos_x] = '0';
		window -> map[window -> player_pos_y][window -> player_pos_x - 1] = 'P';
		window -> player_pos_x = window -> player_pos_x - 1;
		draw_window(window);
	}
	else if (window -> map[window -> player_pos_y][window -> player_pos_x - 1] == 'E' &&
		is_c_in_map(window) == 0)
		{
			ft_printf("You are the Flunkyball champion\n");
			close_game(window);		
		}
}

void	move_right(t_window *window)
{
	if (window -> map[window -> player_pos_y][window -> player_pos_x + 1] == '0' ||
		window -> map[window -> player_pos_y][window -> player_pos_x + 1] == 'C')
	{
		window -> map[window -> player_pos_y][window -> player_pos_x] = '0';
		window -> map[window -> player_pos_y][window -> player_pos_x + 1] = 'P';
		window -> player_pos_x = window -> player_pos_x + 1;
		draw_window(window);
	}
	else if (window -> map[window -> player_pos_y][window -> player_pos_x + 1] == 'E' &&
		is_c_in_map(window) == 0)
		{
			ft_printf("You are the Flunkyball champion\n");
			close_game(window);		
		}
}