/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:05:34 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/14 16:58:46 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	load_walls(t_wolf *wolf)
{
	wolf->wall = (t_img *)malloc(sizeof(t_img) * 9);
	wolf->wall[0].img = mlx_xpm_file_to_image(wolf->mlx, "texture/e18.xpm",
		&wolf->wall[0].width, &wolf->wall[0].height);
	wolf->wall[1].img = mlx_xpm_file_to_image(wolf->mlx, "texture/wall_1.xpm"
		, &wolf->wall[1].width, &wolf->wall[1].height);
	wolf->wall[2].img = mlx_xpm_file_to_image(wolf->mlx,
		"texture/colorstone.xpm", &wolf->wall[2].width, &wolf->wall[2].height);
	wolf->wall[3].img = mlx_xpm_file_to_image(wolf->mlx, "texture/eagle.xpm",
		&wolf->wall[3].width, &wolf->wall[3].height);
	wolf->wall[4].img = mlx_xpm_file_to_image(wolf->mlx, "texture/vovan2.xpm",
		&wolf->wall[4].width, &wolf->wall[4].height);
	wolf->wall[5].img = mlx_xpm_file_to_image(wolf->mlx, "texture/wood.xpm",
		&wolf->wall[5].width, &wolf->wall[5].height);
	wolf->wall[7].img = mlx_xpm_file_to_image(wolf->mlx,
		"texture/pol.xpm", &wolf->wall[7].width,
			&wolf->wall[7].height);
	wolf->wall[6].img = mlx_xpm_file_to_image(wolf->mlx, "texture/pol_good.xpm",
		&wolf->wall[6].width, &wolf->wall[6].height);
	wolf->wall[8].img = mlx_xpm_file_to_image(wolf->mlx, "texture/door_wood.xpm",
		&wolf->wall[8].width, &wolf->wall[8].height);
}


void	load_menu(t_wolf *wolf)
{
	wolf->menu = (t_img *)malloc(sizeof(t_img) * 3);
	wolf->menu[0].img = mlx_xpm_file_to_image(wolf->mlx, "texture/newgame.xpm",
		&wolf->menu[0].width, &wolf->menu[0].height);
	wolf->menu[1].img = mlx_xpm_file_to_image(wolf->mlx, "texture/wolfabout.xpm"
		, &wolf->menu[1].width, &wolf->menu[1].height);
	wolf->menu[2].img = mlx_xpm_file_to_image(wolf->mlx,
		"texture/wolfquit.xpm", &wolf->menu[2].width, &wolf->menu[2].height);
}

void	load_sprite(t_wolf *wolf)
{
	wolf->spr = (t_img *)malloc(sizeof(t_img) * 3);
	wolf->spr[0].img = mlx_xpm_file_to_image(wolf->mlx, "texture/pillar.xpm",
		&wolf->menu[0].width, &wolf->menu[0].height);
	wolf->spr[1].img = mlx_xpm_file_to_image(wolf->mlx, "texture/greenligh.xpm"
		, &wolf->menu[1].width, &wolf->menu[1].height);
	wolf->spr[2].img = mlx_xpm_file_to_image(wolf->mlx,
		"texture/pillar.xpm", &wolf->menu[2].width, &wolf->menu[2].height);
	wolf->load = (t_img *)malloc(sizeof(t_img) * 2);
	wolf->load[0].img = mlx_xpm_file_to_image(wolf->mlx, "texture/load.xpm",
		&wolf->load[0].width, &wolf->load[0].height);
	wolf->load[1].img = mlx_xpm_file_to_image(wolf->mlx, "texture/load_load.xpm"
		, &wolf->load[1].width, &wolf->load[1].height);
}

void	load_texture(t_wolf *wolf)
{
	load_walls(wolf);
	load_menu(wolf);
	load_sprite(wolf);
}
