/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:07:55 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/21 11:57:45 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*src;

	i = 0;
	ch = (unsigned char)c;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (src[i] == ch)
			return (src + i);
		i++;
	}
	return (NULL);
}
