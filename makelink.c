/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:33:45 by efriedma          #+#    #+#             */
/*   Updated: 2018/03/22 18:43:10 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void	find_coord(char **dptr, s_tetro *link)
{
	int i;
	int x;
	int ctr;

	ctr = 0;
	i = 0;
	x = 0;
	while (x < 4)
	{
		if (dptr[x][i] == '#')
		{
			link->x[ctr] = i;
			link->y[ctr] = x;
			printf("\nctr: %d\nx: %d, y: %d\n\n",ctr, link->x[ctr], link->y[ctr]);
			ctr++;
		}
		i++;
		if (i == 4)
		{
			x++;
			i = 0;
		}
	}
}

char	**one2(char *str, s_tetro *link)
{
	char **dptr;
	int	i;
	int ctr;

	ctr = 0;
	i = 0;
	dptr = ft_memalloc(sizeof(char*) * 4);
	while (i < 4)
	{
		dptr[i] = ft_strnew(4);
		ft_strncpy(dptr[i], &str[ctr], 4);
		ctr += 5;
		i++;
	}
	find_coord(dptr, link);
	return (dptr);
}

void	set_char(s_tetro *mark)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (x < 4)
	{
		if (mark->arr[x][i] == '#')
			mark->arr[x][i] = mark->letter;
		i++;
		if (i == 4)
		{
			i = 0;
			x++;
		}
	}
}


s_tetro	*make_list(char **tetro, int size)
{
	s_tetro		*snew;
	s_tetro		*buf;
	s_tetro		*last;
	int			i;

	i = 0;
	snew = (s_tetro*)malloc(sizeof(s_tetro));
	buf = snew;
	snew->prev = 0;
	while (i < size)
	{
		snew->arr = one2(tetro[i], snew);
		snew->index = i;
		snew->letter = 'A' + snew->index;
		if (i)
			snew->prev = last;
		if (i + 1 == size)
		{
			snew->next = 0;
			break;
		}
		else
			snew->next = (s_tetro*)malloc(sizeof(s_tetro) * 2);
		set_char(snew);
		last = snew;
		snew = snew->next;
		i++;
	}
	return (buf);
}

int main()
{
	s_tetro	*snew;
	char	*tetri;
/*
	tetri = ft_strsub(".#..\n###.\n....\n....\n", 0, 20);
	new = make_list(&tetri, 1);
	printf("%s\n", new->arr[0]);
	printf("%s\n", new->arr[1]);
	printf("%s\n", new->arr[2]);
	printf("%s\n", new->arr[3]);
	transform(new);
	printf("%d, %d\n", new->x[0], new->y[0]);
	printf("%d, %d\n", new->x[1], new->y[1]);
	printf("%d, %d\n", new->x[2], new->y[2]);
	printf("%d, %d\n", new->x[3], new->y[3]);
*/
	tetri = ft_strsub("####\n....\n....\n....\n", 0, 20);
	snew = make_list(&tetri, 1);
	transform(snew);
	printf("%s\n", snew->arr[0]);
	printf("%s\n", snew->arr[1]);
	printf("%s\n", snew->arr[2]);
	printf("%s\n", snew->arr[3]);
	printf("%d, %d\n", snew->x[0], snew->y[0]);
	printf("%d, %d\n", snew->x[1], snew->y[1]);
	printf("%d, %d\n", snew->x[2], snew->y[2]);
	printf("%d, %d\n", snew->x[3], snew->y[3]);

	place_tetri(snew);

	free(tetri);
	free(snew);
	return (0);
}
