/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapgen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:37:49 by msisto            #+#    #+#             */
/*   Updated: 2024/05/02 14:22:48 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coll_cycle(t_mtx *mtx)
{
	usleep(550000 / 6);
	img_put_y(mtx);
	if (mtx->i == 3)
		mtx->i = 0;
	else
		mtx->i++;
}

void	finish_screen_window(t_mtx *mtx, int ver)
{
	free(mtx->mlx);
	mtx->mlx = mlx_init();
	mtx->img_size = 500;
	mtx->finish_screen = NULL;
	mtx->death_finish = NULL;
	if (ver == 1)
	{
		mtx->finish_screen = mlx_xpm_file_to_image(mtx->mlx,
				"./img/finish_screen.xpm", &mtx->img_size, &mtx->img_size);
		mtx->mlx_win = mlx_new_window(mtx->mlx, mtx->img_size,
				mtx->img_size, "finish");
	}
	else
	{
		mtx->death_finish = mlx_xpm_file_to_image(mtx->mlx,
				"./img/death_finish_screen.xpm",
				&mtx->img_size, &mtx->img_size);
		mtx->mlx_win = mlx_new_window(mtx->mlx, mtx->img_size,
				mtx->img_size, "death");
	}
}

void	img_put_x(t_mtx *mtx)
{
	if (mtx->map_gen_x > mtx->len)
	{
		mtx->map_gen_x = 0;
		return ;
	}
	which_img(mtx);
	mtx->map_gen_x++;
	img_put_x(mtx);
}

void	img_put_y(t_mtx *mtx)
{
	char	*str;

	if (mtx->map_gen_y >= mtx->height)
	{
		mtx->map_gen_y = 0;
		return ;
	}
	img_put_x(mtx);
	mtx->map_gen_y++;
	str = ft_itoa(mtx->mosse);
	mlx_string_put(mtx->mlx, mtx->mlx_win, 150, 150, 1, str);
	free(str);
	img_put_y(mtx);
}
