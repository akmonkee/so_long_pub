/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:07:23 by msisto            #+#    #+#             */
/*   Updated: 2024/05/02 12:24:46 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct matrix
{
	char	**map;
	int		len;
	int		height;
	int		p_x;
	int		p_y;
	int		o_x;
	int		o_y;
	int		img_size;
	int		map_gen_x;
	int		map_gen_y;
	void	*opponent_left;
	void	*opponent_right;
	void	*opponent_down;
	void	*opponent_up;
	void	*floor;
	void	*walls;
	void	*exit;
	void	**coll;
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;
	void	*finish_screen;
	void	*death_finish;
	void	*mlx;
	void	*mlx_win;
	int		keycode;
	int		mosse;
	int		i;
}	t_mtx;

void	surprise_search(char *file, t_mtx *mtx);
void	blocade(char *file, t_mtx *mtx);
void	chase(char *line, int line_len);
void	more_blocades(char *file, int height, int p, t_mtx *mtx);
void	structure_check(char *line, int i, int n_line);
int		search(char *line, char c);
void	check_content(int player, int exit, int coins, t_mtx *mtx);
char	**map_ver(char *file, t_mtx *mtx);
void	flood_fill(char *file, t_mtx *mtx);
void	find_player(char **map_m, t_mtx *mtx);
void	find_opponent(char **map_m, t_mtx *mtx);
void	fill(char **map, t_mtx *mtx, int cur_x, int cur_y);
int		post_fill_check(char **map, t_mtx *mtx);
void	window_maker(t_mtx *mtx);
void	img_put(t_mtx *mtx);
void	img_put_y(t_mtx *mtx);
void	img_put_x(t_mtx *mtx);
void	which_img(t_mtx *mtx);
void	img(t_mtx *mtx, void *img);
void	xpm_to_img(t_mtx *mtx);
int		key_check(int keycode, t_mtx *mtx);
void	move_right(t_mtx *mtx);
void	move_up(t_mtx *mtx);
void	move_down(t_mtx *mtx);
void	move_left(t_mtx *mtx);
void	op_move_right(t_mtx *mtx);
void	op_move_up(t_mtx *mtx);
void	op_move_down(t_mtx *mtx);
void	op_move_left(t_mtx *mtx);
void	game_finish(t_mtx *mtx);
void	death_finish(t_mtx *mtx);
int		coin_check(t_mtx *mtx);
void	matrix_free(t_mtx *mtx);
void	game_exit(t_mtx *mtx);
int		esc_button(int keycode, t_mtx *mtx);
void	which_direction_p(t_mtx *mtx);
void	which_direction_o(t_mtx *mtx);
int		x_button(t_mtx *mtx);
void	coll_frames(t_mtx *mtx);
int		coll_cycle(t_mtx *mtx);
void	finish_screen_window(t_mtx *mtx, int ver);

#endif
