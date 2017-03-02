/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:32:33 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/02 15:32:35 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_player(t_wolf *wolf)
{
	wolf->plr.pos.x = 20;
	wolf->plr.pos.y = 20;
	wolf->plr.dir.x = -1;
	wolf->plr.dir.y = 0;
	wolf->plr.plane.x = 0;
	wolf->plr.plane.y = 0.66;

}

void	init_camera(t_wolf *wolf)
{
	wolf->ray.camera.x = 2. * wolf->i / (double)WIN_X - 1;
	wolf->ray.pos.x = wolf->plr.pos.x;
	wolf->ray.pos.y = wolf->plr.pos.y;
	wolf->ray.dir.x = wolf->plr.dir.x + wolf->plr.plane.x * wolf->ray.camera.x;
	wolf->ray.dir.y = wolf->plr.dir.y + wolf->plr.plane.y * wolf->ray.camera.x;
	wolf->mapa.map_x = (int)wolf->ray.pos.x;
	wolf->mapa.map_y = (int)wolf->ray.pos.y;
	wolf->mapa.sidedist.x = 0;
	wolf->mapa.sidedist.y = 0;
	wolf->mapa.deltadist.x = sqrt(1 + (wolf->ray.dir.y * wolf->ray.dir.y) /
		(wolf->ray.dir.x * wolf->ray.dir.x));
	wolf->mapa.deltadist.y = sqrt(1 + (wolf->ray.dir.x * wolf->ray.dir.x) /
		(wolf->ray.dir.y * wolf->ray.dir.y));
	wolf->mapa.step_x = 0;
	wolf->mapa.step_y = 0;
	wolf->mapa.hit = 0;
	wolf->mapa.side = 0;
	wolf->mapa.perpwalldist = 0;
	wolf->mapa.line_height = 0;
	wolf->mapa.draw_start = 0;
	wolf->mapa.draw_end = 0;
}

void	raycasting(t_wolf *wolf)
{
	init_player(wolf);
	while (++wolf->i < WIN_X)
	{
		init_camera(wolf);
		if (wolf->ray.dir.x < 0)
		{
			wolf->mapa.step_x = -1;
			wolf->mapa.sidedist.x = (wolf->ray.pos.x - wolf->mapa.map_x) * wolf->mapa.deltadist.x;
		}
		else
		{
			wolf->mapa.step_x = 1;
			wolf->mapa.sidedist.x = (wolf->mapa.map_x + 1. - wolf->ray.pos.x) * wolf->mapa.deltadist.x;
		}
		if (wolf->ray.dir.y < 0)
		{
			wolf->mapa.step_y = -1;
			wolf->mapa.sidedist.y = (wolf->ray.pos.y - wolf->mapa.map_y) * wolf->mapa.deltadist.y;
		}
		else
		{
			wolf->mapa.step_y = 1;
			wolf->mapa.sidedist.y = (wolf->mapa.map_y + 1. - wolf->ray.pos.y) * wolf->mapa.deltadist.y;
		}
		while (wolf->mapa.hit == 0)
		{
			if (wolf->mapa.sidedist.x < wolf->mapa.sidedist.y)
			{
				wolf->mapa.sidedist.x += wolf->mapa.deltadist.x;
				wolf->mapa.map_x += wolf->mapa.step_x;
				wolf->mapa.side = 0;
			}
			else
			{
				wolf->mapa.sidedist.y += wolf->mapa.deltadist.y;
				wolf->mapa.map_y += wolf->mapa.step_y;
				wolf->mapa.side = 1;
			}
			if (wolf->map[wolf->mapa.map_x][wolf->mapa.map_y] > '0')
				wolf->mapa.hit = 1;
		}
		if (wolf->mapa.side == 0)
			wolf->mapa.perpwalldist = (wolf->mapa.map_x - wolf->ray.pos.x + (1 - wolf->mapa.step_x) / 2) / wolf->ray.dir.x;
		else
			wolf->mapa.perpwalldist = (wolf->mapa.map_y - wolf->ray.pos.y + (1 - wolf->mapa.step_y) / 2) / wolf->ray.dir.y;
		wolf->mapa.line_height = (int)(WIN_Y / wolf->mapa.perpwalldist);
		wolf->mapa.draw_start = -wolf->mapa.line_height / 2 + WIN_Y / 2;
		if (wolf->mapa.draw_start < 0)
			wolf->mapa.draw_start = 0;
		wolf->mapa.draw_end = wolf->mapa.line_height / 2 + WIN_Y / 2;
		if (wolf->mapa.draw_end < 0)
			wolf->mapa.draw_end = WIN_Y - 1;
	  //choose wall color
    //  ColorRGB color;
		switch(wolf->map[wolf->mapa.map_x][wolf->mapa.map_y])
		{
        	case '1':  wolf->color = 255;  break; //red
        	case '2':  wolf->color = 125000;  break; //green
    		case '3':  wolf->color = 999999;   break; //blue
			case '4':  wolf->color = 12345678;   break; //blue
    		case '5':  wolf->color = 555555;  break; //white
    		case '0':  wolf->color = 16777215;  break; //white
     	}
     	if (wolf->mapa.side == 1)
			wolf->color = wolf->color / 2;
	 	draw_line2(wolf, wolf->i, wolf->mapa.draw_start, wolf->mapa.draw_end);
	}
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->image, 0, 0);
}
