/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:11:05 by msisto            #+#    #+#             */
/*   Updated: 2024/04/30 16:12:08 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_mtx	mtx;

	if (argc == 2)
	{
		mtx.keycode = 100;
		surprise_search(argv[1], &mtx);
		mtx.map = map_ver(argv[1], &mtx);
		flood_fill(argv[1], &mtx);
		mtx.mosse = 0;
		window_maker(&mtx);
		mlx_key_hook(mtx.mlx_win, key_check, &mtx);
		mlx_hook(mtx.mlx_win, 17, 0, x_button, &mtx);
		mlx_loop_hook(mtx.mlx, coll_cycle, &mtx);
		mlx_loop(mtx.mlx);
	}
	else
		return (ft_printf("Error\nno map?"));
	return (0);
}
