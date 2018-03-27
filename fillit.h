/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:11:10 by emgounto          #+#    #+#             */
/*   Updated: 2018/03/22 22:39:49 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

typedef struct	t_tetro
{
	int		index;
	char	letter;
	char	**arr;
	int		max;
	int		x[4];
	int		y[4];
	struct	t_tetro *next;
	struct	t_tetro *prev;
}				s_tetro;

typedef struct	t_map
{
	int			size;
	char		**go;
}				s_map;

char				**makemap(int size);
void				ft_read(char *str);
void				ft_usage(char *str);
size_t				ft_totsize(int fp);
void				ft_verify(char **tetro, int size);
void				ft_tetro(char *str, int size);
int					ft_side(char *ptr);
void				ft_error(void);
int					shapevalid(char *ptr);
void				ft_cpybin(char **tetro, int size);
void				locate_points(char **btetro, int size);
void				transform(s_tetro *target);
int					place_tetri(s_tetro *piece);
int					ft_isupper(char a);

#endif
