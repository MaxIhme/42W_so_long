/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:29:31 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/05 11:25:18 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int err_code)
{
	write(2, "Error\n", 6);
	if(err_code == 1)
		ft_printf("Wrong character in map\n"); // also write(2...?
	if(err_code == 2)
		ft_printf("Wrong border\n");
	if(err_code == 3)
		ft_printf("Only one P, one E and at least one C allowed\n");
	if(err_code == 4)
		ft_printf("Map not rectangular\n");
	if(err_code == 5)
		ft_printf("no path found\n");
	exit(1);
}

void	free_mem(t_window *window)
{
	int i;

	i = 0;
	
	while (i < window -> map_height)
	{
		//free(window -> map[i]);
		i++;
	}
	//free(window -> map);
}

int	close_game(t_window *window)
{
// 	// davor alle allocs freen
	free_mem(window);
	// mlx_clear_window(window -> mlx_ptr, window -> win_ptr);
	// mlx_destroy_image(window -> mlx_ptr, window -> player_ptr);
	// mlx_destroy_image(window -> mlx_ptr, window -> collect_ptr);
	// mlx_destroy_image(window -> mlx_ptr, window -> exit_ptr);
	// mlx_destroy_image(window -> mlx_ptr, window -> wall_ptr);
	// mlx_destroy_image(window -> mlx_ptr, window -> floor_ptr);

	// mlx_destroy_window(window -> mlx_ptr, window -> win_ptr);
 	exit(0);
 	return (0);
 }

int	main(int argc, char **argv)
{
	char *path;
	t_window window;
	
	path = argv[1];
	init_map(path, &window);
	remove_new_line(&window);
	check_map(&window);
	// int i = 0;
	// while(i<8)
	// {
	// 	ft_printf("%s\n", window.map[i]);
	// 	i++;
	// }


	

	window.mlx_ptr = mlx_init();
	

	window.player_ptr = mlx_xpm_file_to_image(window.mlx_ptr, PATH_PLAYER, &window.tile_width, &window.tile_height);
	window.collect_ptr = mlx_xpm_file_to_image(window.mlx_ptr, PATH_ITEM, &window.tile_width, &window.tile_height);
	window.exit_ptr = mlx_xpm_file_to_image(window.mlx_ptr, PATH_EXIT, &window.tile_width, &window.tile_height);
	window.wall_ptr = mlx_xpm_file_to_image(window.mlx_ptr, PATH_WALL, &window.tile_width, &window.tile_height);
	window.floor_ptr = mlx_xpm_file_to_image(window.mlx_ptr, PATH_FLOOR, &window.tile_width, &window.tile_height);

	draw_window(&window);

	//win_ptr = mlx_new_window(ptrs.mlx_ptr, (player.width * map.width), (player.height * map.height), "new Window");
	//mlx_pixel_put(mlx_ptr, win_ptr, 150, 150, 47483647);
	mlx_key_hook(window.win_ptr, key_event, &window);
	//hook 17 ist der Kreuz Knopf links oben
	mlx_hook(window.win_ptr, 17, (void *)0, close_game, &window);

	// if(!img_ptr)
	//  	ft_printf("%p\n", img_ptr);
	// getcwd(pat, 200);
	// ft_printf("%s\n", pat);
	
	
	
	//test_ptr = mlx_put_image_to_window(ptrs.mlx_ptr, win_ptr, player.ptr, 0, 0);
	// fd = open("img/firefox_.xpm",O_RDONLY);
	// ft_printf("%d\n", fd);
	
	mlx_loop(window.mlx_ptr);


	return (0);
	// output an std error? 
	// what if last line has no characters, ok?
	// must not relink makefile
	// look for valid path to all collectables
	// collect everything, then exit. only that way is allowed!
	// struct correct?
	// window destruct
	// look for unused variables
	// check map name with ending
	// player left right direction
	///////////////////////////////////// can you pass an Exit without exiting? or map check right
	// falls vorher beenden dann muss map nicht gefreed werden
	// nullpointer bei init abfangen
}

