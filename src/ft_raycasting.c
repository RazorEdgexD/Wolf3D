/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:32:33 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/08 18:56:33 by aosobliv         ###   ########.fr       */
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
	if (PLR_POS_X == 0 && PLR_POS_Y == 0)
	{
		ft_putendl("\tNo player...\n\n\n\tAdd 'p' on map!");
		exit(111);
	}
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

void	raycasting(t_wolf *wolf)
{
	mlx_destroy_image(wolf->mlx, wolf->image);
	wolf->image = mlx_new_image(wolf->mlx, WIN_X, WIN_Y);
	wolf->i = -1;
	while (++wolf->i < WIN_X)
	{
		init_camera(wolf);
		if (RAY_DIR_X < 0)
		{
			STEP_X = -1;
			SIDE_DIS_X = (RAY_POS_X - MAP_X) * DELT_DIS_X;
		}
		else
		{
			STEP_X = 1;
			SIDE_DIS_X = (MAP_X + 1. - RAY_POS_X) * DELT_DIS_X;
		}
		if (RAY_DIR_Y < 0)
		{
			STEP_Y = -1;
			SIDE_DIS_Y = (RAY_POS_Y - MAP_Y) * DELT_DIS_Y;
		}
		else
		{
			STEP_Y = 1;
			SIDE_DIS_Y = (MAP_Y + 1. - RAY_POS_Y) * DELT_DIS_Y;
		}
		while (wolf->mapa.hit == 0)
		{
			if (SIDE_DIS_X < SIDE_DIS_Y)
			{
				SIDE_DIS_X += DELT_DIS_X;
				MAP_X += STEP_X;
				MAP_SIDE = 0;
			}
			else
			{
				SIDE_DIS_Y += DELT_DIS_Y;
				MAP_Y += STEP_Y;
				MAP_SIDE = 1;
			}
			if (chmo(wolf, MAP_Y, MAP_X) > '0')
				wolf->mapa.hit = 1;
		}
		if (MAP_SIDE == 0)
			D_P_WALL = (MAP_X - RAY_POS_X + (1 - STEP_X) / 2) / RAY_DIR_X;
		else
			D_P_WALL = (MAP_Y - RAY_POS_Y + (1 - STEP_Y) / 2) / RAY_DIR_Y;
	//	if (D_P_WALL < 0.3)
	//		LINE_H = WIN_Y;
	//	else
			LINE_H = (int)(WIN_Y / D_P_WALL);
		// if (LINE_H > WIN_Y)
		// 	LINE_H = WIN_Y;
		DRAW_START = -LINE_H / 2 + WIN_Y / 2;
		if (DRAW_START < 0)
			DRAW_START = 0;
		DRAW_END = LINE_H / 2 + WIN_Y / 2;
		if (DRAW_END > WIN_Y)
			DRAW_END = WIN_Y - 1;
		wolf->tex_num = wolf->map[MAP_Y][MAP_X] - 1 - '0';
		if (MAP_SIDE == 0)
			wolf->wallx = RAY_POS_Y + D_P_WALL * RAY_DIR_Y;
		else
			wolf->wallx = RAY_POS_X + D_P_WALL * RAY_DIR_X;
		wolf->wallx -= floor(wolf->wallx);

		wolf->text_x = (int)(wolf->wallx * (double)TEX_X);
		if (MAP_SIDE == 0 && RAY_DIR_X > 0)
			wolf->text_x = TEX_X - wolf->text_x - 1;
		if (MAP_SIDE == 1 && RAY_DIR_Y < 0)
			wolf->text_x = TEX_X - wolf->text_x - 1;

		draw_texture(wolf, wolf->i, DRAW_START, DRAW_END);
		if (MAP_SIDE == 0 && RAY_DIR_X > 0)
		{
			wolf->f_wallx = MAP_X;
			wolf->f_wally = MAP_Y + wolf->wallx;
		}
		else if (MAP_SIDE == 0 && RAY_DIR_X < 0)
		{
			wolf->f_wallx = MAP_X + 1.;
			wolf->f_wally = MAP_Y + wolf->wallx;
		}
		else if (MAP_SIDE == 1 && RAY_DIR_Y > 0)
		{
			wolf->f_wallx = MAP_X + wolf->wallx;
			wolf->f_wally = MAP_Y;
		}
		else
		{
			wolf->f_wallx = MAP_X + wolf->wallx;
			wolf->f_wally = MAP_Y + 1.;
		}
		wolf->dist_wall = D_P_WALL;
		wolf->dist_plr = 0;
		if (DRAW_END < 0)
			DRAW_END = WIN_Y;
			draw_floor_sel(wolf, wolf->i);

	}
	wolf->old_time = wolf->time;
	wolf->time = clock();
	wolf->frametime = (wolf->time - wolf->old_time) / CLOCKS_PER_SEC;
	wolf->move_speed = wolf->frametime * 3.5;
	wolf->rot_speed = wolf->frametime * 2.5;
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->image, 0, 0);
}
