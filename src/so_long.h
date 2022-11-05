/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:31:13 by mrehberg          #+#    #+#             */
/*   Updated: 2022/11/01 19:03:05 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
#include "../minilibx_opengl_20191021/mlx.h"

# define PATH_PLAYER "img/Player64x64.xpm"
# define PATH_ITEM "img/Collect64x64.xpm"
# define PATH_EXIT "img/Exit64x64.xpm"
# define PATH_WALL "img/Wall64x64.xpm"
# define PATH_FLOOR "img/Floor64x64.xpm"
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_window
{
	int	map_width;
	int	map_height;
	char	**map;
	int tile_width;
	int tile_height;
	int	player_pos_x;
	int	player_pos_y;
	int	count_c_e;
	void *mlx_ptr;
	void *win_ptr;
	void *player_ptr;
	void *collect_ptr;
	void *wall_ptr;
	void *exit_ptr;
	void *floor_ptr;
}	t_window;


//-------------------------------- so_long.c

void	error(int err_code);
int	close_game(t_window *window);
int		main(int argc, char **argv);

//-------------------------------- checks.c

int	count_lines(int fd);
void	init_map(char *path, t_window *window);
int	check_char(t_window *window);
int count_width(t_window *window);
int check_map(t_window *window);

//-------------------------------- checks_2.c

void	remove_new_line(t_window *window);
int	check_border_horizontal(char *line);
void	check_border(t_window *window);
void	check_P_E_C(t_window *window);
void	check_rectangularity(t_window *window);

//-------------------------------- checks_path.c

int**	copy_map(t_window *window, int **map_copy);
void	show_copy_map(t_window *window, int **map_copy);
int	substitute_zeros(int **map_copy, int run_height, int run_width, t_window *window);
int	scan_map_for_twos(t_window *window, int **map_copy);
void	check_path(t_window *window);

//-------------------------------- draw_window.c

void	draw_window(t_window *window);
int	is_c_in_map(t_window *window);

//-------------------------------- move_player.c

int	key_event(int key, t_window *window);
void	move_down(t_window *window);
void	move_up(t_window *window);
void	move_right(t_window *window);
void	move_left(t_window *window);

#endif
