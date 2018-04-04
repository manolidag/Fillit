/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:24:49 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/27 22:16:15 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int nb)
{
	size_t i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	size_t	len;
	int		neg;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		len = ft_size(n) + 1;
		neg = 1;
	}
	else
		len = ft_size(n);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	ptr[--len] = n % 10 + '0';
	while (n /= 10)
		ptr[--len] = n % 10 + '0';
	if (neg)
		ptr[0] = '-';
	return (ptr);
}
