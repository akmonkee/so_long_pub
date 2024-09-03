/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caramba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:38:37 by msisto            #+#    #+#             */
/*   Updated: 2024/05/03 11:33:04 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	surprise_search(char *file, t_mtx *mtx)
{
	int		fd;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(ft_printf("Error\nArrested: illegal items found\n"));
	len = ft_strlen(file) - 1;
	if (len < 4)
		exit(ft_printf("Error\nArrested: illegal items found\n"));
	if (file[len] != 'r')
		exit(ft_printf("Error\nArrested: illegal items found\n"));
	if (file[len - 1] != 'e')
		exit(ft_printf("Error\nArrested: illegal items found\n"));
	if (file[len - 2] != 'b')
		exit(ft_printf("Error\nArrested: illegal items found\n"));
	blocade(file, mtx);
}

void	chase(char *line, int line_len)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line) - 1;
	if (line[len] == '\n')
		len--;
	if (len != line_len)
		exit(ft_printf("Error\nArrested: couldn't run\n"));
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'C'
				|| line[i] == 'E' || line[i] == 'P' || line[i] == 'O'))
			exit(ft_printf("Error\nArrested: couldn't run\n"));
		i++;
	}
}

void	more_blocades(char *file, int height, int p, t_mtx *mtx)
{
	int		c;
	int		fd;
	int		i;
	int		e;
	char	*line;

	i = 0;
	e = 0;
	c = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		p += search(line, 'P');
		e += search(line, 'E');
		c += search(line, 'C');
		structure_check(line, i, height);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	check_content(p, e, c, mtx);
}

void	blocade(char *file, t_mtx *mtx)
{
	int		fd;
	int		line_len;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	line_len = ft_strlen(line) - 1;
	if ((line == NULL && height == 0) || line_len <= 0)
		exit(1);
	if (line[line_len] == '\n')
		line_len--;
	while (line != NULL)
	{
		chase(line, line_len);
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	more_blocades(file, height, 0, mtx);
	mtx->height = height;
	mtx->len = line_len;
}

void	flood_fill(char *file, t_mtx *mtx)
{
	char	**map_test;
	int		i;
	int		ver;

	i = 0;
	ver = 0;
	map_test = map_ver(file, mtx);
	find_player(map_test, mtx);
	fill(map_test, mtx, mtx->p_x, mtx->p_y);
	ver = post_fill_check(map_test, mtx);
	while (i < mtx->height)
	{
		free(map_test[i]);
		i++;
	}
	free(map_test);
	if (ver == 1)
		exit(ft_printf("Error\nArrested: no way out?\n"));
}
