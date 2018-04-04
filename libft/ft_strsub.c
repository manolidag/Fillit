/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:50:22 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/26 21:18:41 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	ptr = ft_strnew(len);
	if (!s)
		return (0);
	if (ptr == NULL)
		return (NULL);
	ft_memmove(ptr, s + start, len);
	return (ptr);
}
