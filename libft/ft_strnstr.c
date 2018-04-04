/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:31:00 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/22 11:23:47 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	begin;
	size_t	current;

	begin = 0;
	current = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[begin] && n > begin)
	{
		if (s1[begin + current] == s2[current] && begin + current < n)
			current++;
		else
		{
			current = 0;
			begin++;
		}
		if (!s2[current])
			return ((char *)s1 + begin);
	}
	return (0);
}
