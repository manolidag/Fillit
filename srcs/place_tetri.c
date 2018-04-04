/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:41:54 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/04 01:11:13 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int		check(t_tetro *piece, char **map, t_map *map1)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (isinbounds(piece, map1->size))
	{
		while (i < 4)
		{
			if (ft_isupper(map[piece->y[i]][piece->x[i]]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	place_tetri(t_tetro *piece, t_map *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map->go[piece->y[i]][piece->x[i]] = piece->letter;
		i++;
	}
}

int		solve(void *tmp, t_map *map)
{
	int		i;
	t_tetro	*piece;

	piece = tmp;
	i = 0;
	if (!piece)
		return (1);
	while (i < map->size * map->size)
	{
		if (check(piece, map->go, map))
		{
			place_tetri(piece, map);
			if (solve(piece->next, map))
				return (1);
			else
			{
				ft_remove(piece->letter, map->go, map->size);
				transform(piece, map, 0);
				transform(piece->next, map, 7);
			}
		}
		else if (!transform(piece, map, 0))
			transform(piece, map, 7);
		i++;
	}
	return (0);
}

void	start(t_tetro *piece, t_map *map)
{
	while (!solve(piece, map))
	{
		plus_map(map);
		transform(piece, map, 1);
	}
	printmap(map->go, map->size);
}
