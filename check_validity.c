/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:12:54 by efriedma          #+#    #+#             */
/*   Updated: 2018/03/14 16:35:38 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		twochars(char *ptr)
{
	size_t	x;
	int		ctr;
	int		per;

	per = 0;
	ctr = 0;
	x = -1;
	while (ptr[++x])
		if (ptr[x] == '#')
			ctr++;
	x = -1;
	while (ptr[++x])
		if (ptr[x] == '.')
			per++;
	printf("%d tetriminos & %d periods\n", ctr, per);
	if (ctr != 4 || per != 12)
	{
		ft_putstr("error in two chars\n");
		return (0);
	}
	return (ctr);
}

int		charvalid(char *ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '.'  || ptr[i] == '#' || ptr[i] == '\n')
			i++;
		else
		{
			ft_putstr("error in char valid\n");
			return (0);
		}
	}
	return (1);
}

int		shapevalid(char *ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
	{
		if (i + 1 % 5 == 0 && ptr[i] != '\n' && i != 0)
		{
			ft_putstr("newline error\n");
			return (0);
		}
		i++;
	}
	i = 0;
	if (!twochars(ptr) || !charvalid(ptr) || !ft_side(ptr))
	{
		ft_putstr("error in last if statement of shapevalid\n");
		ft_error();
	}
	return (1);
}
