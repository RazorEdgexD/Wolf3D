/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:04:22 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/27 19:04:24 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_wolf(t_wolf *wolf)
{
	wolf->map_len = 0;
	wolf->map_height = 0;
	wolf->color = 16777215;
	wolf->i = -1;
	wolf->mlx = mlx_init();
	wolf->win = mlx_new_window(wolf->mlx, WIN_X, WIN_Y, "Wolf3D by Razor");
	wolf->image = mlx_new_image(wolf->mlx, WIN_X, WIN_Y);
}

int		main(int argc, char **argv)
{
	t_wolf	wolf;

	if (argc == 2)
	{
		init_wolf(&wolf);
		read_map(argv[1], &wolf);
		ft_hooks(&wolf);
		mlx_loop(wolf.mlx);
	}
	else
		ft_error(5);
	return (0);
}
