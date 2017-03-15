/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:04:22 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/15 15:54:46 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_player(t_wolf *wolf)
{
	wolf->plr.dir.x = -1;
	wolf->plr.dir.y = 0;
	wolf->plr.plane.x = 0;
	wolf->plr.plane.y = 0.66;
	wolf->time = 0;
	wolf->old_time = 0;
	wolf->move_speed = 0;
	wolf->rot_speed = 0;
	wolf->ms_k = 3;
	wolf->plr.f_pos.x = PLR_POS_X;
	wolf->plr.f_pos.y = PLR_POS_Y;
	if (PLR_POS_X == 0 && PLR_POS_Y == 0)
	{
		ft_putendl("\tNo player...\n\n\n\tAdd 'p' on map!");
		exit(111);
	}
}

void	init_wolf(t_wolf *wolf)
{
	wolf->map_len = 0;
	wolf->start = 0;
	wolf->map_height = 0;
	wolf->color = 255;
	wolf->men.menu = 1;
	wolf->k = 1;
	PLR_POS_X = 13.5;
	PLR_POS_Y = 12.5;
	wolf->mlx = mlx_init();
	wolf->win = mlx_new_window(wolf->mlx, WIN_X, WIN_Y, "Wolf3D by Razor");
	wolf->image = mlx_new_image(wolf->mlx, WIN_X, WIN_Y);
}

void	*music(void *lol)
{
	lol = NULL;
	while (1)
	{
		system("afplay music/help.mp3");
		sleep(40);
	}
	return (NULL);
}

void	*music_start(void *lol)
{
	lol = NULL;
	while (1)
	{
		system("afplay -v 1 music/giran.mp3");
		sleep(125);
	}
	return (NULL);
}



int		main(int argc, char **argv)
{
	t_wolf		wolf;


	if (argc == 2)
	{
		wolf.i = -1;
		wolf.men.flag = 0;
		wolf.mus = 1;
		init_wolf(&wolf);
		read_map(argv[1], &wolf);
		//pthread_create(&wolf.tread[1], NULL, music_start, NULL);
		init_player(&wolf);
		load_texture(&wolf);
		mlx_loop_hook(wolf.mlx, ft_hooks, &wolf);
		mlx_loop(wolf.mlx);
	}
	else
		ft_error(5);
	return (0);
}
