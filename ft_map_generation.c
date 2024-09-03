/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:12:30 by msisto            #+#    #+#             */
/*   Updated: 2024/05/02 12:15:17 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img(t_mtx *mtx, void *img)
{
	mlx_put_image_to_window(mtx->mlx, mtx->mlx_win, img,
		mtx->map_gen_x * mtx->img_size,
		mtx->map_gen_y * mtx->img_size);
}

void	xpm_to_img(t_mtx *mtx)
{
	mtx->opponent_up = mlx_xpm_file_to_image(mtx->mlx,
			"./img/opponent_up.xpm", &mtx->img_size, &mtx->img_size);
	mtx->opponent_down = mlx_xpm_file_to_image(mtx->mlx,
			"./img/opponent_down.xpm", &mtx->img_size, &mtx->img_size);
	mtx->opponent_right = mlx_xpm_file_to_image(mtx->mlx,
			"./img/opponent_right.xpm", &mtx->img_size, &mtx->img_size);
	mtx->opponent_left = mlx_xpm_file_to_image(mtx->mlx,
			"./img/opponent_left.xpm", &mtx->img_size, &mtx->img_size);
	mtx->player_up = mlx_xpm_file_to_image(mtx->mlx, "./img/player_up.xpm",
			&mtx->img_size, &mtx->img_size);
	mtx->player_down = mlx_xpm_file_to_image(mtx->mlx, "./img/player_down.xpm",
			&mtx->img_size, &mtx->img_size);
	mtx->player_left = mlx_xpm_file_to_image(mtx->mlx, "./img/player_left.xpm",
			&mtx->img_size, &mtx->img_size);
	mtx->player_right = mlx_xpm_file_to_image(mtx->mlx,
			"./img/player_right.xpm", &mtx->img_size, &mtx->img_size);
	coll_frames(mtx);
	mtx->exit = mlx_xpm_file_to_image(mtx->mlx, "./img/exit.xpm",
			&mtx->img_size, &mtx->img_size);
	mtx->floor = mlx_xpm_file_to_image(mtx->mlx, "./img/floor.xpm",
			&mtx->img_size, &mtx->img_size);
	mtx->walls = mlx_xpm_file_to_image(mtx->mlx, "./img/walls.xpm",
			&mtx->img_size, &mtx->img_size);
}

void	which_img(t_mtx *mtx)
{
	if (mtx->map[mtx->map_gen_y][mtx->map_gen_x] == '1')
		img(mtx, mtx->walls);
	else if (mtx->map[mtx->map_gen_y][mtx->map_gen_x] == 'E')
		img(mtx, mtx->exit);
	else if (mtx->map[mtx->map_gen_y][mtx->map_gen_x] == 'C')
		img(mtx, mtx->coll[mtx->i]);
	else if (mtx->map[mtx->map_gen_y][mtx->map_gen_x] == 'O')
		which_direction_o(mtx);
	else if (mtx->map[mtx->map_gen_y][mtx->map_gen_x] == 'P')
		which_direction_p(mtx);
	else
		img(mtx, mtx->floor);
}

void	img_put(t_mtx *mtx)
{
	mlx_clear_window(mtx->mlx, mtx->mlx_win);
	mtx->map_gen_x = 0;
	mtx->map_gen_y = 0;
	img_put_y(mtx);
}

void	window_maker(t_mtx *mtx)
{
	mtx->img_size = 100;
	mtx->i = 0;
	mtx->map_gen_x = 0;
	mtx->map_gen_y = 0;
	mtx->mlx = mlx_init();
	mtx->mlx_win = mlx_new_window(mtx->mlx, (mtx->len + 1) * mtx->img_size,
			mtx->height * mtx->img_size, "Game");
	find_opponent(mtx->map, mtx);
	xpm_to_img(mtx);
	img_put_y(mtx);
}
