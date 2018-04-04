/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:54:15 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/28 19:31:36 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)src;
	s2 = (char *)dst;
	if (s1 < s2)
	{
		while (len-- > 0)
			s2[len] = s1[len];
	}
	else
		ft_memcpy(s2, s1, len);
	return (s2);
}
