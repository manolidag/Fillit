/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:11:13 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/20 17:23:01 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char *s1;
	char *s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (n-- > 0)
		*s1++ = *s2++;
	return (dst);
}
