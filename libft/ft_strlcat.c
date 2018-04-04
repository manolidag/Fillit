/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:58:22 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/21 14:28:20 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t res;

	i = 0;
	while (dstsize > i && dst[i])
		i++;
	if (dstsize == i)
		return (dstsize + ft_strlen(src));
	res = i + ft_strlen(src);
	ft_strncat(dst, src, dstsize - i - 1);
	return (res);
}
