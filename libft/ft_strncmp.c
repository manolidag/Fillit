/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:56:22 by emgounto          #+#    #+#             */
/*   Updated: 2018/03/06 13:03:24 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	cmp1;
	char	cmp2;
	size_t	i;

	i = 0;
	while (i < n && (*(s1 + i) != 0 && *(s1 + i) == *(s2 + i)))
		i++;
	if (i < n)
	{
		cmp1 = *(s1 + i);
		cmp2 = *(s2 + i);
		return ((unsigned char)cmp1 - (unsigned char)cmp2);
	}
	return (0);
}
