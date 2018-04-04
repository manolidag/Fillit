/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:28:36 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/28 18:51:32 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *buf;

	new = f(lst);
	if (!lst)
		return (NULL);
	if (new == NULL)
		return (NULL);
	buf = new;
	while (lst->next)
	{
		lst = lst->next;
		buf->next = f(lst);
		if (buf->next == NULL)
			return (NULL);
		buf = buf->next;
	}
	return (new);
}
