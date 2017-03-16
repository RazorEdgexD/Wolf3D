/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:09:32 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/16 15:00:44 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error(int code)
{
	if (code == 1)
	{
		ft_putendl("\tWrong Map Length or Height...");
		exit(1);
	}
	if (code == 2)
	{
		ft_putendl("\tWrong Char...");
		exit(2);
	}
	if (code == 3)
	{
		ft_putendl("\tNo Walls on side lines || All Char Walls...");
		exit(3);
	}
	if (code == 4)
	{
		ft_putendl("\tCannot open file...\n(Usage ./wolf3d [map_name].wolf)");
		exit(4);
	}
	if (code == 5)
	{
		ft_putendl("\tUsage ./wolf3d [map_name].wolf | Start");
		exit(5);
	}
}

char	chmo(t_wolf *wolf, int y, int x)
{
	if ((y < 0 || x < 0) || x >= wolf->map_len - 1 || y >= wolf->map_height - 1)
		return (127);
	return (wolf->map[y][x]);
}

void	init_camera(t_wolf *wolf)
{
	wolf->ray.camera.x = 2. * wolf->i / (double)WIN_X - 1;
	RAY_POS_X = wolf->plr.pos.x;
	RAY_POS_Y = wolf->plr.pos.y;
	RAY_DIR_X = wolf->plr.dir.x + wolf->plr.plane.x * wolf->ray.camera.x;
	RAY_DIR_Y = wolf->plr.dir.y + wolf->plr.plane.y * wolf->ray.camera.x;
	MAP_X = (int)RAY_POS_X;
	MAP_Y = (int)RAY_POS_Y;
	SIDE_DIS_X = 0;
	SIDE_DIS_Y = 0;
	DELT_DIS_X = sqrt(1 + (RAY_DIR_Y * RAY_DIR_Y) /
		(RAY_DIR_X * RAY_DIR_X));
	DELT_DIS_Y = sqrt(1 + (RAY_DIR_X * RAY_DIR_X) /
		(RAY_DIR_Y * RAY_DIR_Y));
	STEP_X = 0;
	STEP_Y = 0;
	wolf->mapa.hit = 0;
	MAP_SIDE = 0;
	D_P_WALL = 0;
	LINE_H = 0;
	DRAW_START = 0;
	DRAW_END = 0;
	wolf->tex_num = 0;
	wolf->wallx = 0;
}

int		close_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

void	restart(t_wolf *wolf, double x, double y, int lvl)
{
	pthread_create(&wolf->tread[0], NULL, music, NULL);
	free_mass(wolf);
	wolf->men.menu = 0;
	wolf->lvl = lvl;
	PLR_POS_X = x;
	PLR_POS_Y = y;
	init_camera(wolf);
	wolf->plr.dir.x = -1;
	wolf->plr.dir.y = 0;
	wolf->plr.plane.x = 0;
	wolf->plr.plane.y = 0.66;
}
