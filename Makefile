# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgounto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 14:40:27 by emgounto          #+#    #+#              #
#    Updated: 2018/04/04 00:26:42 by emgounto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = fillit

LIBFT := libft/

SRC = srcs/isinbounds.c srcs/side_check.c srcs/read_file.c srcs/check_validity.c
SRC += srcs/place_tetri.c srcs/makelink.c srcs/transform.c srcs/freemap.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT)
	gcc $(OBJ) -L. libft/libft.a srcs/main.c -o fillit

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
