/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:05:34 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/16 14:40:22 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	load_walls(t_wolf *wolf)
{
	wolf->wall = (t_img *)malloc(sizeof(t_img) * 18);
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
	wolf->wall[8].img = mlx_xpm_file_to_image(wolf->mlx, "texture/door_wood.xpm"
		, &wolf->wall[8].width, &wolf->wall[8].height);
}

void	load_menu(t_wolf *wolf)
{
	wolf->menu = (t_img *)malloc(sizeof(t_img) * 4);
	wolf->menu[0].img = mlx_xpm_file_to_image(wolf->mlx, "texture/newgame.xpm",
		&wolf->menu[0].width, &wolf->menu[0].height);
	wolf->menu[1].img = mlx_xpm_file_to_image(wolf->mlx, "texture/wolfabout.xpm"
		, &wolf->menu[1].width, &wolf->menu[1].height);
	wolf->menu[2].img = mlx_xpm_file_to_image(wolf->mlx,
		"texture/wolfquit.xpm", &wolf->menu[2].width, &wolf->menu[2].height);
	wolf->menu[3].img = mlx_xpm_file_to_image(wolf->mlx, "texture/winner.xpm",
		&wolf->menu[3].width, &wolf->menu[3].height);
}

void	load_sprite(t_wolf *wolf)
{
	wolf->wall[9].img = mlx_xpm_file_to_image(wolf->mlx, "texture/dim.xpm",
		&wolf->wall[9].width, &wolf->wall[9].height);
	wolf->wall[10].img = mlx_xpm_file_to_image(wolf->mlx, "texture/pet.xpm"
		, &wolf->wall[10].width, &wolf->wall[10].height);
	wolf->wall[11].img = mlx_xpm_file_to_image(wolf->mlx,
		"texture/vil.xpm", &wolf->wall[11].width, &wolf->wall[11].height);
	wolf->wall[12].img = mlx_xpm_file_to_image(wolf->mlx, "texture/kos.xpm",
		&wolf->wall[12].width, &wolf->wall[12].height);
	wolf->wall[13].img = mlx_xpm_file_to_image(wolf->mlx,
		"texture/vov.xpm", &wolf->wall[13].width, &wolf->wall[13].height);
	wolf->wall[14].img = mlx_xpm_file_to_image(wolf->mlx, "texture/san.xpm",
		&wolf->wall[14].width, &wolf->wall[14].height);
	wolf->wall[15].img = mlx_xpm_file_to_image(wolf->mlx,
		"texture/purplestone.xpm", &wolf->wall[15].width,
			&wolf->wall[15].height);
	wolf->wall[16].img = mlx_xpm_file_to_image(wolf->mlx, "texture/mossy.xpm",
		&wolf->wall[16].width, &wolf->wall[16].height);
	wolf->wall[17].img = mlx_xpm_file_to_image(wolf->mlx, "texture/hand.xpm",
		&wolf->wall[17].width, &wolf->wall[17].height);
}

void	load_texture(t_wolf *wolf)
{
	load_walls(wolf);
	load_menu(wolf);
	load_sprite(wolf);
}
