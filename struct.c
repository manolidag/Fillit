/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 15:44:21 by emgounto          #+#    #+#             */
/*   Updated: 2018/03/18 20:48:51 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct	t_tetro
{
	int		x[4];
	int		y[4];
	char	**arr;
	struct	t_tetro *next;
}				s_tetro;
*/

void	locate_points(char **btetro, int size)
{
	int i;
	int x;
	int y;
	int k;
	int j;
	s_tetro *new;
	s_tetro *temp;

	printf("size: %d\n", size);
	new = (s_tetro*)malloc(sizeof(s_tetro));
	temp = new;
	i = 0;
	x = 1;
	y = 4;
	k = 0;
	j = 0;
	while (i < size)
	{
		new = (s_tetro*)malloc(sizeof(s_tetro));
		new->next = (s_tetro*)malloc(sizeof(s_tetro));
		while (j < 16)
		{
			while (x < 5)
			{
				if (btetro[i][j] == '1')
				{
					new->x[i] = x;
					new->y[i] = y;
					printf("%d, %d\n", new->x[i], new->y[i]);
				}
				j++;
				x++;
			}
			x = 1;
			y--;
		}
		printf("value of i %d\n", i);
		i++;
		new = new->next;
	}
	new->next = 0;
}
