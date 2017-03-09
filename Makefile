# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 13:28:10 by aosobliv          #+#    #+#              #
#    Updated: 2017/03/09 20:09:52 by aosobliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g #-O3

MLX = -lmlx -framework AppKit -framework OpenGl

LIB = libft/libft.a

SRCS = main.c									\
		read_map.c								\
		print_info.c							\
		texture.c								\
		ft_tools.c								\
		ft_tools2.c								\
		ft_hooks.c								\
		ft_raycasting.c							\
		ft_move.c								\

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(BINS) $(MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	make -C libft/ clean
	/bin/rm -f $(BINS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
