/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:01:31 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/22 11:31:46 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *in, const char *find)
{
	int i;
	int j;
	int k;

	i = 0;
	if (find[0] == '\0')
		return ((char *)in);
	while (in[i])
	{
		j = i;
		k = 0;
		while (in[j] == find[k])
		{
			j++;
			k++;
			if (find[k] == '\0')
				return (char *)(&in[i]);
		}
		i++;
	}
	return (0);
}
