/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:44:06 by efriedma          #+#    #+#             */
/*   Updated: 2018/03/18 20:46:44 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		space(char b)
{
	if ((a >= 'A' && a <= 'Z') && (b >= 'A' && b <= 'Z'))
		return (0);
	return (1);
}
  
void		place_tetri(s_map *map, s_tetro *tetri, int size)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (x < size)
	{
		if (space(map[x][i]))
		{
			map[x][i] = tetri[x][i];
		}
		else
		{
			x++;
		}
		if (i == size - 1)
		{
			x++;
			i = -1;
		}
		i++;
	}
	printmap(map, size);
}

char	**makemap(int size)
{
	char	**map;
	int		i;

	map = (char**)malloc(sizeof(char *) * size);
	i = 0;
	ft_putstr("map:\n");
	while (i < size)
	{
		map[i] = (char*)ft_memalloc(size + 1);
		map[i] = ft_memset(map[i], 46, size);
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("map finished\n");
	return (map);
}

int main()
{
	char **ptr;
	ptr = makemap(4);
	printf("map:");
	int i;

	char **tetri = (char**)malloc(sizeof(char*) * 4);
	tetri[0] = "AAAA";
	tetri[1] = "....";
	tetri[2] = "....";
	tetri[3] = "....";

	char **tetri1 = (char**)malloc(sizeof(char*) * 4);
	tetri1[0] = "....";
	tetri1[1] = "BBBB";
	tetri1[2] = "....";
	tetri1[3] = "....";

	char **tetri2 = (char**)malloc(sizeof(char*) * 4);
	tetri2[0] = "....";
	tetri2[1] = "....";
	tetri2[2] = "CCCC";
	tetri2[3] = "....";

	place_tetri(ptr, tetri, 4);
	ft_putstr("first piece placed\n");
	place_tetri(ptr, tetri1, 4);
	ft_putstr("second piece placed\n");
	place_tetri(ptr, tetri2, 4);
	ft_putstr("third piece placed\n");
	
	printmap(ptr, 4);

	free(tetri);
	free(tetri1);
	free(tetri2);
	free(ptr);

	return (0);
}
