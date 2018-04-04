/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:43:02 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/28 15:57:56 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	newlist = (t_list *)malloc(sizeof(*newlist));
	if (newlist == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = malloc(content_size);
		if (newlist->content == NULL)
			return (NULL);
		ft_memcpy((newlist->content), content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
