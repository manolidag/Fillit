/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:26:12 by efriedma          #+#    #+#             */
/*   Updated: 2018/03/18 21:26:47 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**makemap(int size)
{
	char	**map;
	int		i;

	map = (char**)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map[i] = (char*)ft_memalloc(size + 1);
		map[i] = ft_memset(map[i], 46, size);
		i++;
	}
	return (map);
}
