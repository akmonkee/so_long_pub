/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:37:29 by msisto            #+#    #+#             */
/*   Updated: 2024/04/29 12:33:24 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_mtx *mtx)
{
	if (mtx->map[mtx->p_y][mtx->p_x + 1] != '1')
	{
		if (mtx->map[mtx->p_y][mtx->p_x + 1] == 'E')
		{
			mtx->map_gen_x = coin_check(mtx);
			if (mtx->map_gen_x == 1)
			{
				ft_printf("you didnt eat enough\n");
				return ;
			}
			else
				game_finish(mtx);
		}
		if (mtx->map[mtx->p_y][mtx->p_x + 1] == 'O')
			death_finish(mtx);
		mtx->map[mtx->p_y][mtx->p_x] = '0';
		mtx->map[mtx->p_y][mtx->p_x + 1] = 'P';
		mtx->p_x++;
		mtx->mosse++;
		op_move_left(mtx);
		ft_printf("mosse: %d\n", mtx->mosse);
	}
	else
		ft_printf("what are you trying to do, eat a wall?\n");
}

void	move_left(t_mtx *mtx)
{
	if (mtx->map[mtx->p_y][mtx->p_x - 1] != '1')
	{
		if (mtx->map[mtx->p_y][mtx->p_x - 1] == 'E')
		{
			mtx->map_gen_x = coin_check(mtx);
			if (mtx->map_gen_x == 1)
			{
				ft_printf("you didnt eat enough\n");
				return ;
			}
			else
				game_finish(mtx);
		}
		if (mtx->map[mtx->p_y][mtx->p_x - 1] == 'O')
			death_finish(mtx);
		mtx->map[mtx->p_y][mtx->p_x] = '0';
		mtx->map[mtx->p_y][mtx->p_x - 1] = 'P';
		mtx->p_x--;
		mtx->mosse++;
		op_move_right(mtx);
		ft_printf("mosse: %d\n", mtx->mosse);
	}
	else
		ft_printf("what are you trying to do, eat a wall?\n");
}

void	move_down(t_mtx *mtx)
{
	if (mtx->map[mtx->p_y + 1][mtx->p_x] != '1')
	{
		if (mtx->map[mtx->p_y + 1][mtx->p_x] == 'E')
		{
			mtx->map_gen_x = coin_check(mtx);
			if (mtx->map_gen_x == 1)
			{
				ft_printf("you didnt eat enough\n");
				return ;
			}
			else
				game_finish(mtx);
		}
		if (mtx->map[mtx->p_y + 1][mtx->p_x] == 'O')
			death_finish(mtx);
		mtx->map[mtx->p_y][mtx->p_x] = '0';
		mtx->map[mtx->p_y + 1][mtx->p_x] = 'P';
		mtx->p_y++;
		mtx->mosse++;
		op_move_up(mtx);
		ft_printf("mosse: %d\n", mtx->mosse);
	}
	else
		ft_printf("what are you trying to do, eat a wall?\n");
}

void	move_up(t_mtx *mtx)
{
	if (mtx->map[mtx->p_y - 1][mtx->p_x] != '1')
	{
		if (mtx->map[mtx->p_y - 1][mtx->p_x] == 'E')
		{
			mtx->map_gen_x = coin_check(mtx);
			if (mtx->map_gen_x == 1)
			{
				ft_printf("you didnt eat enough\n");
				return ;
			}
			else
				game_finish(mtx);
		}
		if (mtx->map[mtx->p_y - 1][mtx->p_x] == 'O')
			death_finish(mtx);
		mtx->map[mtx->p_y][mtx->p_x] = '0';
		mtx->map[mtx->p_y - 1][mtx->p_x] = 'P';
		mtx->p_y--;
		mtx->mosse++;
		op_move_down(mtx);
		ft_printf("mosse: %d\n", mtx->mosse);
	}
	else
		ft_printf("what are you trying to do, eat a wall?\n");
}

int	key_check(int keycode, t_mtx *mtx)
{
	mtx->keycode = keycode;
	if (keycode == 119)
		move_up(mtx);
	else if (keycode == 97)
		move_left(mtx);
	else if (keycode == 115)
		move_down(mtx);
	else if (keycode == 100)
		move_right(mtx);
	else if (keycode == 65307)
		game_exit(mtx);
	return (0);
}
