/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 16:49:44 by aderragu          #+#    #+#             */
/*   Updated: 2015/12/25 16:49:45 by aderragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

static char	*ft_strsetnew(char c, int size)
{
	char	*str;
	int		i;

	str = (char*)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (size--)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		**ft_createmap(int bsq)
{
	char	**map_y;
	char	*map_x;
	int		i;

	map_y = (char**)malloc((bsq + 1) * sizeof(char*));
	if (!map_y)
		return (NULL);
	i = bsq;
	map_y[i] = NULL;
	while (--i >= 0)
	{
		map_x = ft_strsetnew('.', bsq);
		map_y[i] = map_x;
	}
	return (map_y);
}

void		ft_display_map(char **map, int sze_sqr, int bonus)
{
	int		cnti;
	int		cntj;

	cnti = 0;
	cntj = 0;
	if (map == NULL)
		return ;
	if (bonus >= 2)
		ft_putstr(PUR);
	while (cnti < sze_sqr)
	{
		while (cntj < sze_sqr)
		{
			write(1, &(map[cnti][cntj]), 1);
			if (bonus == 1 || bonus == 3)
				write(1, " ", 1);
			cntj++;
		}
		write(1, "\n", 1);
		cnti++;
		cntj = 0;
	}
	if (bonus == 1 || bonus == 3)
		ft_putstr(EOC);
}

int			ft_bonus_init(int ac, char **av)
{
	int		bonus;
	int		cnt;

	bonus = 0;
	ac -= 2;
	cnt = 0;
	while (cnt < ac)
	{
		if (av[cnt + 2][0] == 's')
			bonus++;
		if (av[cnt + 2][0] == 'c')
			bonus += 2;
		cnt++;
	}
	return (bonus);
}
