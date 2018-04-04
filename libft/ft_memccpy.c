/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:02:29 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/20 17:46:07 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*s1;
	const unsigned char		*s2;
	unsigned char			ch;

	ch = (unsigned char)c;
	s1 = (unsigned char *)dst;
	s2 = (const unsigned char *)src;
	while (n-- > 0)
	{
		if (*s2 == ch)
		{
			*s1++ = *s2++;
			return (s1);
		}
		*s1++ = *s2++;
	}
	return (NULL);
}
