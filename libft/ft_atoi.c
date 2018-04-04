/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:10:45 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/26 21:12:33 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	size_t	k;
	int		neg;
	int		num;

	neg = 1;
	num = 0;
	i = 0;
	while (*(str + i) == '\n' || *(str + i) == '\t' ||
		*(str + i) == '\r' || *(str + i) == '\v' ||
		*(str + i) == '\f' || *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		neg = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	k = i;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	return ((int)(num * neg));
}
