/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 10:17:12 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/23 10:31:09 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = (char *)ft_memalloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = (char *)ft_memset(ptr, '\0', size);
	return (ptr);
}
