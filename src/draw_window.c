/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:43:31 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/01 13:41:48 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_window(t_window *window)
{
	static int cycle = 0;
	int run_width;
	int run_height;

	if (cycle == 0)
	{
		window -> win_ptr = mlx_new_window(window -> mlx_ptr, (window -> tile_width * window -> map_width), (window -> tile_height * window -> map_height), "so long");

	}

	run_height = 0;
	while (run_height < window -> map_height)
	{
		run_width = 0;
		while (run_width < window -> map_width)
		{
			if (window -> map[run_height][run_width] == 'P')
				mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr, window -> player_ptr, 
				(run_width * window -> tile_width), (run_height * window -> tile_height));
			if (window -> map[run_height][run_width] == 'C')
				mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr, window -> collect_ptr, 
				(run_width * window -> tile_width), (run_height * window -> tile_height));
			if (window -> map[run_height][run_width] == 'E')
				mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr, window -> exit_ptr, 
				(run_width * window -> tile_width), (run_height * window -> tile_height));
			if (window -> map[run_height][run_width] == '0')
				mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr, window -> floor_ptr, 
				(run_width * window -> tile_width), (run_height * window -> tile_height));
			if (window -> map[run_height][run_width] == '1')
				mlx_put_image_to_window(window -> mlx_ptr, window -> win_ptr, window -> wall_ptr, 
				(run_width * window -> tile_width), (run_height * window -> tile_height));
			run_width++;
		}
		run_height++;
	}
	if (cycle)
		ft_printf("Stepcount: %d\n", cycle);
	cycle++;
}

/**
 * @brief 
 * 
 * @param window 
 * @return number of collectibles
 */
int	is_c_in_map(t_window *window)
{
	int collectible;
	int run_width;
	int run_height;
	
	collectible = 0;
	run_height = 0;
	while (run_height < window -> map_height)
	{
		run_width = 0;
		while (run_width < window -> map_width)
		{
			if (window -> map[run_height][run_width] == 'C')
				collectible++;
			run_width++;
		}
		run_height++;
	}
	return (collectible);
}