/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 18:32:26 by aderragu          #+#    #+#             */
/*   Updated: 2015/12/28 10:10:19 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int	main(int argc, char **argv)
{
	t_tetri	*tetris;
	int		pcs;
	int		cnt;
	int		bonus;

	pcs = 0;
	cnt = -1;
	bonus = 0;
	tetris = ft_global_check(argv[1], &pcs);
	if (argc > 2)
		bonus = ft_bonus_init(argc, argv);
	if (tetris == NULL || !pcs || pcs > 26 || (argc > 2 && bonus == 0))
		ft_putstr("error\n");
	else
	{
		ft_letter_assignation(tetris);
		ft_start(tetris, pcs, bonus);
	}
	free(tetris);
	return (0);
}
