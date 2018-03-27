/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:42:27 by efriedma          #+#    #+#             */
/*   Updated: 2018/03/22 21:19:47 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	push_y_up(s_tetro *target)
{
	int i;
	int max;
 
	i = 0;
	max = -1;
	while (i < 4)
	{
		if (target->y[i] > max)
			max = target->y[i];
		i++;
	}
	i = 0;
	printf("max y value: %d\n", max);
	if (max != 4)
	{
		while (i < 4)
		{
			target->y[i] = target->y[i] + max;
			printf("\ntransformed y value: %d\n", target->y[i]);
			i++;
		}
	}
}

void	push_y_down(s_tetro *target)
{
	int i;
	int min;

	i = 0;
	min = 10;
	while (i < 4)
	{
		if (target->y[i] < min)
			min = target->y[i];
		i++;
	}
	if (min < 10)
	{
		i = 0;
		while (i < 4)
		{
			target->y[i] = target->y[i] - min;
			i++;
		}
	}
}

void	push_x_left(s_tetro *target)
{
	int i;
	int min;

	i = 0;
	min = 10;
	while (i < 4)
	{
		if (target->x[i] < min)
			min = target->x[i];
		i++;
	}
	if (min < 10)
	{
		i = 0;
		while (i < 4)
		{
			target->x[i] = target->x[i] - min;
			i++;
			printf("\ntransformed x value: %d\n", target->x[i]);
		}
	}
}

void	push_x_right(s_tetro *target)
{
	int i;
	int max;

	i = 0;
	max = -1;
	while (i < 4)
	{
		if (target->x[i] > max)
			max = target->x[i];
		i++;
	}
	if (max != -1 && max != 4)
	{
		i = 0;
		printf("max x value: %d\n", max);
		while (i < 4)
		{
			target->x[i] = target->x[i] + max;
			i++;
		}
	}
}

void	transform(s_tetro *target)
{
	push_y_up(target);
	push_x_left(target);
}
