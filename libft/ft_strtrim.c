/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:31:05 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/26 18:10:35 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	size_t	x;

	if (!s)
		return (0);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;
	x = ft_strlen(s);
	while (x != 0 && ((s[x - 1] == ' ') || (s[x - 1] == '\n')
				|| (s[x - 1] == '\t')))
		x--;
	ptr = (char *)malloc(sizeof(char) * (x + 1));
	if (ptr)
	{
		ft_strncpy(ptr, s, x);
		ptr[x] = '\0';
	}
	return (ptr);
}
