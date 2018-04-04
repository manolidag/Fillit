/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:30:13 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/04 00:57:57 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	push_all(t_tetro *target)
{
	push_y_up(target);
	push_x_left(target);
}

int		ft_side(char *ptr)
{
	int		i;
	int		side;

	side = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '#')
		{
			if (i && ptr[i - 1] == '#')
				side += 1;
			if (i + 1 < 20 && ptr[i + 1] == '#')
				side += 1;
			if (i + 5 < 20 && ptr[i + 5] == '#')
				side += 1;
			if (i - 5 > -1 && ptr[i - 5] == '#')
				side += 1;
		}
		i++;
	}
	if (side == 6 || side == 8)
		return (side);
	return (0);
}
