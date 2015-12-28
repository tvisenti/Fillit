/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 09:47:59 by aderragu          #+#    #+#             */
/*   Updated: 2015/12/28 11:41:51 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

static t_tetri	*ft_check_count(t_tetri *tetri_array, char *file_name, int pcs)
{
	char		*buf;
	int			fd;

	if ((buf = malloc(sizeof(char) * (21 * pcs) + 1)) == NULL)
		return (NULL);
	if ((fd = open(file_name, O_RDONLY, 0555)) == -1)
		return (NULL);
	buf[21 * pcs] = '\0';
	read(fd, buf, (21 * pcs));
	if (buf[21 * pcs - 1] == '\0')
	{
		free(buf);
		return (tetri_array);
	}
	free(buf);
	return (NULL);
}

int				ft_norme_vector(int x, int y, int x_ref, int y_ref)
{
	int			p;
	int			p_ref;
	int			p_diff;

	p_ref = x_ref + y_ref;
	p = x + y;
	p_diff = p - p_ref;
	p = ft_abs(x) + ft_abs(y);
	if (p_diff > 1 || p_diff < -1 || p > 3)
		return (0);
	return (1);
}

static t_tetri	*ft_pattern_check(char *buf, t_tetri *tetri)
{
	int			cur;
	int			shrp_cnt;
	int			x_ref;
	int			y_ref;

	cur = 0;
	shrp_cnt = 0;
	while (buf[cur] != '#')
		cur++;
	x_ref = cur % 5;
	y_ref = cur / 5;
	if (ft_p1(buf, tetri, x_ref, y_ref))
		if (ft_p2(buf, tetri, x_ref, y_ref))
			if (ft_p3(buf, tetri, x_ref, y_ref))
				return (tetri);
	return (NULL);
}

static t_tetri	*ft_block_check(char *buf, t_tetri *tetri)
{
	int			cur;
	int			dot_cnt;
	int			shrp_cnt;
	int			nwl_cnt;

	cur = -1;
	dot_cnt = 0;
	shrp_cnt = 0;
	nwl_cnt = 0;
	while (buf[++cur] && (buf[cur] == '.' || buf[cur] == '#' ||
		buf[cur] == '\n'))
	{
		if (buf[cur] == '.')
			dot_cnt++;
		else if (buf[cur] == '\n')
			nwl_cnt++;
		else if (buf[cur] == '#')
			shrp_cnt++;
	}
	if (!(dot_cnt == 12 && shrp_cnt == 4 && (buf[0] == '.' || buf[0] == '#') &&
	((nwl_cnt == 5 && buf[20] == '\n') || (nwl_cnt == 4 && buf[20] == '\0'))))
		return (NULL);
	else
		return (ft_pattern_check(buf, tetri));
}

t_tetri			*ft_global_check(char *file_name, int *pcs)
{
	char		*buf;
	t_tetri		*tetri_array;
	int			fd;
	int			cnt;

	if ((tetri_array = malloc(sizeof(t_tetri) * 27)) == NULL)
		return (NULL);
	cnt = -1;
	if ((buf = malloc(sizeof(char) * (BUFF + 1))) == NULL)
		return (NULL);
	if ((fd = open(file_name, O_RDONLY, 0555)) == -1)
		return (NULL);
	ft_memset(buf, '\0', BUFF + 1);
	while (read(fd, buf, BUFF))
	{
		if (ft_block_check(buf, &(tetri_array[++cnt])) == NULL)
			return (NULL);
		*pcs = *pcs + 1;
		ft_memset(buf, '\0', BUFF + 1);
	}
	free(buf);
	if ((close(fd)) == -1)
		return (NULL);
	tetri_array[*pcs].letter = '|';
	return (ft_check_count(tetri_array, file_name, *pcs));
}
