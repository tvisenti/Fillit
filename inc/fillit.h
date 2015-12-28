/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderragu <aderragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:16:42 by aderragu          #+#    #+#             */
/*   Updated: 2015/12/28 11:44:22 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF 21
# include "colors.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_tetri
{
	int			p1[2];
	int			p2[2];
	int			p3[2];
	char		letter;
}				t_tetri;

t_tetri			*ft_global_check(char *file_name, int *pcs);
int				ft_bonus_init(int ac, char **av);
int				ft_p1(char *buf, t_tetri *tetri, int x_ref, int y_ref);
int				ft_p2(char *buf, t_tetri *tetri, int x_ref, int y_ref);
int				ft_p3(char *buf, t_tetri *tetri, int x_ref, int y_ref);
int				ft_norme_vector(int x, int y, int x_ref, int y_ref);
void			ft_letter_assignation(t_tetri *tetris);
void			ft_start(t_tetri *tetris, int pcs, int bonus);
char			**ft_createmap(int bsq);
void			ft_display_map(char **map, int sze_sqr, int bonus);

int				ft_bsq(int nb);
float			ft_sqrt(int nb);
int				ft_round(float nb);
size_t			ft_strlen(const char *s);
void			ft_putstr(char const *s);
int				ft_abs(int nbr);
void			*ft_memset(void *b, int c, size_t len);

#endif
