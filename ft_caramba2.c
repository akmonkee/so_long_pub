/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caramba2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:35:50 by msisto            #+#    #+#             */
/*   Updated: 2024/04/29 12:51:24 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, t_mtx *mtx, int cur_x, int cur_y)
{
	if (cur_y < 0 || cur_y >= mtx->height || cur_x < 0 || cur_x >= mtx->len
		|| map[cur_y][cur_x] == '1' || map[cur_y][cur_x] == '2')
		return ;
	if (map[cur_y][cur_x] == 'E')
	{
		map[cur_y][cur_x] = '2';
		return ;
	}
	map[cur_y][cur_x] = '2';
	fill(map, mtx, cur_x + 1, cur_y);
	fill(map, mtx, cur_x - 1, cur_y);
	fill(map, mtx, cur_x, cur_y + 1);
	fill(map, mtx, cur_x, cur_y - 1);
}

int	post_fill_check(char **map, t_mtx *mtx)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < mtx->height)
	{
		while (k < mtx->len)
		{
			if (map[i][k] == 'C' || map[i][k] == 'E')
				return (1);
			k++;
		}
		k = 0;
		i++;
	}
	return (0);
}
