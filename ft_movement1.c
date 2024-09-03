/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:09:09 by msisto            #+#    #+#             */
/*   Updated: 2024/04/30 11:47:36 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_exit(t_mtx *mtx)
{
	mlx_destroy_window(mtx->mlx, mtx->mlx_win);
	free(mtx->mlx);
	matrix_free(mtx);
	exit(0);
}

int	esc_button(int keycode, t_mtx *mtx)
{
	mtx->keycode = keycode;
	if (keycode == 65307)
		game_exit(mtx);
}

void	matrix_free(t_mtx *mtx)
{
	mtx->map_gen_x = 0;
	while (mtx->map_gen_x < mtx->height)
	{
		free(mtx->map[mtx->map_gen_x]);
		mtx->map_gen_x++;
	}
	free(mtx->map);
}

void	game_finish(t_mtx *mtx)
{
	mlx_destroy_window(mtx->mlx, mtx->mlx_win);
	finish_screen_window(mtx, 1);
	if (mtx->finish_screen == NULL)
		ft_printf("dio cane\n");
	mlx_put_image_to_window(mtx->mlx, mtx->mlx_win,
		mtx->finish_screen, 0, 0);
	mlx_key_hook(mtx->mlx_win, esc_button, mtx);
	mlx_hook(mtx->mlx_win, 17, 0, x_button, mtx);
	mlx_loop(mtx->mlx);
	matrix_free(mtx);
}

int	coin_check(t_mtx *mtx)
{
	mtx->map_gen_y = 0;
	mtx->map_gen_x = 0;
	while (mtx->map_gen_y < mtx->height)
	{
		while (mtx->map_gen_x < mtx->len)
		{
			if (mtx->map[mtx->map_gen_y][mtx->map_gen_x] == 'C')
				return (1);
			mtx->map_gen_x++;
		}
		mtx->map_gen_x = 0;
		mtx->map_gen_y++;
	}
	return (0);
}
