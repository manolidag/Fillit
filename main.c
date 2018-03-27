/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:36:41 by emgounto          #+#    #+#             */
/*   Updated: 2018/03/18 17:17:17 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(char *str)
{
	ft_putstr("usage: ");
	ft_putstr(str);
	ft_putstr(" input_file\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_read(argv[1]);
	else
		ft_usage(argv[0]);
	return (0);
}
