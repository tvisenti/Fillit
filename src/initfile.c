/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 12:08:24 by aderragu          #+#    #+#             */
/*   Updated: 2015/12/25 18:58:01 by aderragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

static void		ft_clean_map(t_tetri *tetri, char **map, int sze_sqr)
{
	int			pos;
	int			cnt;

	cnt = 0;
	pos = 0;
	while (pos < sze_sqr * sze_sqr && cnt < 4)
	{
		if (map[pos / sze_sqr][pos % sze_sqr] == tetri->letter)
		{
			map[pos / sze_sqr][pos % sze_sqr] = '.';
			cnt++;
		}
		pos++;
	}
}

static int		ft_around(t_tetri *tetri, char **map, int sze_sqr, int pos)
{
	int			x;
	int			y;
	int			px;
	int			py;

	x = pos % sze_sqr;
	y = pos / sze_sqr;
	if (x >= sze_sqr || y >= sze_sqr || x < 0 || y < 0 || map[y][x] != '.')
		return (0);
	px = x + tetri->p1[1];
	py = y + tetri->p1[0];
	if (px >= sze_sqr || py >= sze_sqr || px < 0 || py < 0 ||
			map[py][px] != '.')
		return (0);
	px = x + tetri->p2[1];
	py = y + tetri->p2[0];
	if (px >= sze_sqr || py >= sze_sqr || px < 0 || py < 0 ||
			map[py][px] != '.')
		return (0);
	px = x + tetri->p3[1];
	py = y + tetri->p3[0];
	if (px >= sze_sqr || py >= sze_sqr || px < 0 || py < 0 ||
			map[py][px] != '.')
		return (0);
	return (1);
}

static void		ft_place_tetri(t_tetri *tetri, char **map, int sze_sqr, int pos)
{
	int			x;
	int			y;

	x = pos % sze_sqr;
	y = pos / sze_sqr;
	map[y][x] = tetri->letter;
	map[y + tetri->p1[0]][x + tetri->p1[1]] = tetri->letter;
	map[y + tetri->p2[0]][x + tetri->p2[1]] = tetri->letter;
	map[y + tetri->p3[0]][x + tetri->p3[1]] = tetri->letter;
}

static int		ft_rec_fill(t_tetri *tetris, char **map, int sze_sqr, int pos)
{
	if (tetris->letter == '|')
		return (1);
	while (pos < sze_sqr * sze_sqr)
	{
		if (ft_around(tetris, map, sze_sqr, pos))
		{
			ft_place_tetri(tetris, map, sze_sqr, pos);
			if (ft_rec_fill(tetris + 1, map, sze_sqr, 0))
				return (1);
		}
		pos++;
	}
	ft_clean_map((tetris - 1), map, sze_sqr);
	return (0);
}

void			ft_start(t_tetri *tetris, int pcs, int bonus)
{
	int			sze_sqr;
	char		**map;

	sze_sqr = ft_bsq(pcs);
	if ((map = ft_createmap(sze_sqr)) == NULL)
		return ;
	while (1)
	{
		if (ft_rec_fill(tetris, map, sze_sqr, 0))
			break ;
		sze_sqr++;
		free(map);
		if ((map = ft_createmap(sze_sqr)) == NULL)
			return ;
	}
	ft_display_map(map, sze_sqr, bonus);
	free(map);
}
