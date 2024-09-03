/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caramba1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:04:13 by msisto            #+#    #+#             */
/*   Updated: 2024/04/30 16:11:19 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search(char *line, char c)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] == c)
			res++;
		i++;
	}
	return (res);
}

void	structure_check(char *line, int i, int n_line)
{
	int	l;

	if (i == 0 || i + 1 == n_line)
	{
		while (line[l] != '\n' && line[l])
		{
			if (line[l] != '1')
				exit(ft_printf("Error\nArrested: structure without walls\n"));
			l++;
		}
	}
	else
	{
		if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
			exit(ft_printf("Error\nArrested: structure without walls\n"));
	}
}

void	check_content(int player, int fire_exit, int coins, t_mtx *mtx)
{
	if (player != 1)
		exit(ft_printf("Error\nArrested: no personal?\n"));
	if (fire_exit != 1)
		exit(ft_printf("Error\nArrested: no fire exit?\n"));
	if (coins == 0)
		exit(ft_printf("Error\nArrested: no founds?\n"));
}

char	**map_ver(char *file, t_mtx *mtx)
{
	char	**map_ver;
	int		fd;
	int		k;
	int		i;

	k = 0;
	i = 1;
	fd = open(file, O_RDONLY);
	map_ver = malloc(sizeof(char *) * mtx->height);
	if (map_ver == NULL)
		return (NULL);
	map_ver[0] = get_next_line(fd);
	map_ver[0][mtx->len + 1] = '\0';
	while (i < mtx->height)
	{
		map_ver[i] = get_next_line(fd);
		map_ver[i][mtx->len + 1] = '\0';
		i++;
	}
	return (map_ver);
}

void	find_player(char **map_m, t_mtx *mtx)
{
	int	i;
	int	k;

	i = 1;
	k = 1;
	while (i < mtx->height - 1)
	{
		while (map_m[i][k] && k < mtx->len - 1)
		{
			if (map_m[i][k] == 'P')
			{
				mtx->p_y = i;
				mtx->p_x = k;
			}
			k++;
		}
		k = 1;
		i++;
	}
}
