/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:12:54 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/03 20:47:44 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
	if (ctr != 4 || per != 12)
		return (0);
	return (ctr);
}

int		charvalid(char *ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '.' || ptr[i] == '#' || ptr[i] == '\n')
			i++;
		else
			return (0);
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
			ft_error();
		i++;
	}
	i = 0;
	if (!twochars(ptr) || !charvalid(ptr) || !ft_side(ptr))
		ft_error();
	return (1);
}
