/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:30:13 by efriedma          #+#    #+#             */
/*   Updated: 2018/03/18 20:48:13 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int     three_side(char *ptr, int i, int len)
{
	if ((i && i + 5 < len && ptr[i + 1] == '#' && ptr[i - 1] == '#' && ptr[i + 5] == '#')
			|| (i && i - 5 > -1 && ptr[i + 1] == '#' && ptr[i - 1] == '#' && ptr[i - 5] == '#')
			|| (i && i + 5 < len && i - 5 > -1 && ptr[i - 1] == '#' && ptr[i - 5] == '#' && ptr[i + 5] == '#')
			|| (i && i + 5 < len && i - 5 > -1 && ptr[i + 1] == '#' && ptr[i - 5] == '#' && ptr[i + 5] == '#'))
		return (1);
	return (0);
}

int     two_side(char *ptr, int i, int len)
{
	if ((!i && ptr[i + 1] == '#' && ptr[i + 5] == '#')
			|| (i && i + 5 < len && i - 5 > -1 && ptr[i + 5] == '#' && ptr[i - 5] == '#')
			|| (i && i + 5 < len && ptr[i + 5] == '#' && (ptr[i - 1] == '#' || ptr[i + 1] == '#'))
			|| (i && i - 5 > -1 && ptr[i - 5] == '#' && (ptr[i - 1] == '#' || ptr[i + 1] == '#'))
			|| (i && ptr[i + 1] == '#' && ptr[i - 1] == '#'))
		return (1);
	return (0);	
}

int		one_side(char *ptr, int i, int len)
{
	if ((!i && ptr[i + 1] == '#')
			|| (i && ptr[i - 1] == '#')
			|| (ptr[i + 1] == '#')
			|| ((i + 5 < len && ptr[i + 5] == '#') || (i - 5 > -1 && ptr[i - 5] == '#'))) 
		return (1);
	return (0);
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
			if (three_side(ptr, i, 20))
				side += 3;
			else if (two_side(ptr, i, 20))
				side += 2;
			else if (one_side(ptr, i, 20))
				side += 1;
		}
		i++;
	}
	ft_putstr("side count:");
	ft_putnbr(side);
	ft_putstr("\n");
	if (side == 6 || side == 8)
		return (side);
	return (0);
}
