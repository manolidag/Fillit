/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:22:59 by emgounto          #+#    #+#             */
/*   Updated: 2018/02/27 20:07:01 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_len(char const *s, char c)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			len++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (len);
}

static char		*ft_strndup(const char *s, size_t n)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int				i;
	int				j;
	int				k;
	char			**tab;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_word_len(s, c)) + 1);
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			tab[k++] = ft_strndup(s + j, i - j);
	}
	tab[k] = NULL;
	return (tab);
}
