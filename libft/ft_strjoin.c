/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:11:17 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/27 19:20:25 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_strnew(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (*s1)
		ptr[++i] = *s1++;
	while (*s2)
		ptr[++i] = *s2++;
	ptr[++i] = '\0';
	return (ptr);
}
