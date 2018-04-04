/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:38:18 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/21 13:39:14 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = -1;
	while (++i < len && src[i])
		dst[i] = src[i];
	i -= 1;
	while (++i < len)
		dst[i] = '\0';
	return (dst);
}
