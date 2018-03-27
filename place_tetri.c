/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:41:54 by efriedma          #+#    #+#             */
/*   Updated: 2018/03/22 23:30:37 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	ft_remove(char c, char **map, int size)
{
	int i;
	int x;

	x = 0;
	i = 0;
	//goes through the whole 2d map array, finds all characters we dont
	//want and removes them
	while (x < size)
	{
		if (map[x][i] == c)
			map[x][i] = '.';
		i++;
		if (i == size)
		{
			i = 0;
			x++;
		}
	}
}

int		place(s_tetro *piece, char **map, int size)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < 4)
	{
		printf("\n%d, %d\n", piece->x[i], piece->y[i]);
		if (ft_isupper(map[piece->y[i]][piece->x[i]]))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		map[piece->y[i]][piece->x[i]] = piece->letter;
		i++;
	}
	return (1);
}

void	printmap(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
}

int		place_tetri(s_tetro *piece)
{
	int		i;
	int		z;
	s_map	*map;

	map = (s_map*)malloc(sizeof(s_map));
	map->go = makemap(4);
	i = 0;
	z = 0;
	while (z < 4 && i < 4)
	{
		if (place(piece, map->go, 4))
		{
			if (piece->next != 0)
				piece = piece->next;
			ft_putstr("Piece placed\n");
			z++;
			i++;
		}
		else
		{
			ft_putstr("Piece could not be placed\n");
			i++;
		}
	}
	printmap(map->go, 4);
	return (1);
}
