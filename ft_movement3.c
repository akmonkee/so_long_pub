/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:23:46 by msisto            #+#    #+#             */
/*   Updated: 2024/04/30 16:17:52 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	which_direction_p(t_mtx *mtx)
{
	if (mtx->keycode == 100)
		img(mtx, mtx->player_right);
	else if (mtx->keycode == 97)
		img(mtx, mtx->player_left);
	else if (mtx->keycode == 115)
		img(mtx, mtx->player_down);
	else if (mtx->keycode == 119)
		img(mtx, mtx->player_up);
	else
		img(mtx, mtx->player_right);
}

void	which_direction_o(t_mtx *mtx)
{
	if (mtx->keycode == 100)
		img(mtx, mtx->opponent_left);
	else if (mtx->keycode == 97)
		img(mtx, mtx->opponent_right);
	else if (mtx->keycode == 115)
		img(mtx, mtx->opponent_up);
	else if (mtx->keycode == 119)
		img(mtx, mtx->opponent_down);
	else
		img(mtx, mtx->opponent_left);
}

void	death_finish(t_mtx *mtx)
{
	mlx_destroy_window(mtx->mlx, mtx->mlx_win);
	finish_screen_window(mtx, 0);
	mlx_put_image_to_window(mtx->mlx, mtx->mlx_win,
		mtx->death_finish, 0, 0);
	mlx_key_hook(mtx->mlx_win, esc_button, mtx);
	mlx_hook(mtx->mlx_win, 17, 0, x_button, mtx);
	mlx_loop(mtx->mlx);
	matrix_free(mtx);
}

int	x_button(t_mtx *mtx)
{
	mlx_destroy_window(mtx->mlx, mtx->mlx_win);
	matrix_free(mtx);
	exit(1);
}

void	coll_frames(t_mtx *mtx)
{
	void	**coll;

	coll = (void *)malloc((sizeof(void *) * 4) + 1);
	if (!coll)
		return ;
	coll[0] = mlx_xpm_file_to_image(mtx->mlx, "./img/coll_frame0.xpm",
			&mtx->img_size, &mtx->img_size);
	coll[1] = mlx_xpm_file_to_image(mtx->mlx, "./img/coll_frame1.xpm",
			&mtx->img_size, &mtx->img_size);
	coll[2] = mlx_xpm_file_to_image(mtx->mlx, "./img/coll_frame2.xpm",
			&mtx->img_size, &mtx->img_size);
	coll[3] = mlx_xpm_file_to_image(mtx->mlx, "./img/coll_frame3.xpm",
			&mtx->img_size, &mtx->img_size);
	mtx->coll = coll;
}
