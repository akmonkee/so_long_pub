/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:37:59 by msisto            #+#    #+#             */
/*   Updated: 2024/05/02 12:54:28 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	op_move_right(t_mtx *mtx)
{
	if (mtx->o_x == 0 || mtx->o_y == 0)
		return ;
	if (mtx->map[mtx->o_y][mtx->o_x + 1] != '1' &&
			mtx->map[mtx->o_y][mtx->o_x + 1] != 'C' &&
			mtx->map[mtx->o_y][mtx->o_x + 1] != 'E')
	{
		if (mtx->map[mtx->o_y][mtx->o_x + 1] == 'P')
			death_finish(mtx);
		mtx->map[mtx->o_y][mtx->o_x] = '0';
		mtx->map[mtx->o_y][mtx->o_x + 1] = 'O';
		mtx->o_x++;
	}
}

void	op_move_left(t_mtx *mtx)
{
	if (mtx->o_x == 0 || mtx->o_y == 0)
		return ;
	if (mtx->map[mtx->o_y][mtx->o_x - 1] != '1' &&
		mtx->map[mtx->o_y][mtx->o_x - 1] != 'C' &&
			mtx->map[mtx->o_y][mtx->o_x - 1] != 'E')
	{
		if (mtx->map[mtx->o_y][mtx->o_x - 1] == 'P')
			death_finish(mtx);
		mtx->map[mtx->o_y][mtx->o_x] = '0';
		mtx->map[mtx->o_y][mtx->o_x - 1] = 'O';
		mtx->o_x--;
	}
}

void	op_move_down(t_mtx *mtx)
{
	if (mtx->o_x == 0 || mtx->o_y == 0)
		return ;
	if (mtx->map[mtx->o_y + 1][mtx->o_x] != '1' &&
		mtx->map[mtx->o_y + 1][mtx->o_x] != 'E' &&
			mtx->map[mtx->o_y + 1][mtx->o_x] != 'C')
	{
		if (mtx->map[mtx->o_y + 1][mtx->o_x] == 'P')
			death_finish(mtx);
		mtx->map[mtx->o_y][mtx->o_x] = '0';
		mtx->map[mtx->o_y + 1][mtx->o_x] = 'O';
		mtx->o_y++;
	}
}

void	op_move_up(t_mtx *mtx)
{
	if (mtx->o_x == 0 || mtx->o_y == 0)
		return ;
	if (mtx->map[mtx->o_y - 1][mtx->o_x] != '1' &&
		mtx->map[mtx->o_y - 1][mtx->o_x] != 'E' &&
			mtx->map[mtx->o_y - 1][mtx->o_x] != 'C')
	{
		if (mtx->map[mtx->o_y - 1][mtx->o_x] == 'P')
			death_finish(mtx);
		mtx->map[mtx->o_y][mtx->o_x] = '0';
		mtx->map[mtx->o_y - 1][mtx->o_x] = 'O';
		mtx->o_y--;
	}
}

void	find_opponent(char **map_m, t_mtx *mtx)
{
	int	i;
	int	k;

	i = 1;
	k = 1;
	while (i < mtx->height - 1)
	{
		while (map_m[i][k] && k < mtx->len - 1)
		{
			if (map_m[i][k] == 'O')
			{
				mtx->o_y = i;
				mtx->o_x = k;
				return ;
			}
			k++;
		}
		i++;
		k = 1;
	}
	mtx->o_y = 0;
	mtx->o_x = 0;
}
