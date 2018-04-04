/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:31:27 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/28 18:21:57 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *next;

	temp = *alst;
	while (temp)
	{
		next = temp->next;
		(*del)(temp->content, temp->content_size);
		free(temp);
		temp = next;
	}
	*alst = NULL;
}
