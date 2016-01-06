/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_assignment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:55:25 by aderragu          #+#    #+#             */
/*   Updated: 2016/01/04 18:18:45 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		ft_norme_vector(int x, int y, int x_ref, int y_ref)
{
	int	p;
	int	p_ref;
	int	p_diff;

	p_ref = x_ref + y_ref;
	p = x + y;
	p_diff = p - p_ref;
	p = ft_abs(x) + ft_abs(y);
	if (p_diff > 1 || p_diff < -1 || p > 3)
		return (0);
	return (1);
}

int		ft_p1(char *buf, t_tetri *tetri, int x_ref, int y_ref)
{
	int	cur;
	int	shrp_cnt;

	if (tetri == NULL)
		return (0);
	cur = -1;
	shrp_cnt = 0;
	while (shrp_cnt != 2)
		if (buf[++cur] == '#')
			shrp_cnt++;
	tetri->p1[0] = cur / 5 - y_ref;
	tetri->p1[1] = cur % 5 - x_ref;
	return (ft_norme_vector(tetri->p1[1], tetri->p1[0], 0, 0));
}

int		ft_p2(char *buf, t_tetri *tetri, int x_ref, int y_ref)
{
	int	cur;
	int	shrp_cnt;

	if (tetri == NULL)
		return (0);
	cur = -1;
	shrp_cnt = 0;
	while (shrp_cnt != 3)
		if (buf[++cur] == '#')
			shrp_cnt++;
	tetri->p2[0] = cur / 5 - y_ref;
	tetri->p2[1] = cur % 5 - x_ref;
	return (ft_norme_vector(tetri->p2[1], tetri->p2[0],
				tetri->p1[1], tetri->p1[0]));
}

int		ft_p3(char *buf, t_tetri *tetri, int x_ref, int y_ref)
{
	int	cur;
	int	shrp_cnt;

	if (tetri == NULL)
		return (0);
	cur = -1;
	shrp_cnt = 0;
	while (shrp_cnt != 4)
		if (buf[++cur] == '#')
			shrp_cnt++;
	tetri->p3[0] = cur / 5 - y_ref;
	tetri->p3[1] = cur % 5 - x_ref;
	return (ft_norme_vector(tetri->p3[1], tetri->p3[0],
				tetri->p2[1], tetri->p2[0]));
}

void	ft_letter_assignation(t_tetri *tetris)
{
	int	cnt;

	cnt = 0;
	while (tetris[cnt].letter != '|')
	{
		tetris[cnt].letter = (char)('A' + cnt);
		cnt++;
	}
}
