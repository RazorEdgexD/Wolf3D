/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:05:34 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/09 17:26:17 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	load_texture(t_wolf *wolf)
{
	wolf->wall = (t_img *)malloc(sizeof(t_img) * 9);
	wolf->wall[0].img = mlx_xpm_file_to_image(wolf->mlx, "texture/redbrick.xpm", &wolf->wall[0].width,
		&wolf->wall[0].height);
	if (wolf->wall[0].img == NULL)
		perror ("texture/redbrick.xpm");
	wolf->wall[1].img = mlx_xpm_file_to_image(wolf->mlx, "texture/bluestone.xpm", &wolf->wall[1].width,
		&wolf->wall[1].height);
		printf("P22=%p\n", wolf->wall[1].img);
	wolf->wall[2].img = mlx_xpm_file_to_image(wolf->mlx, "texture/colorstone.xpm", &wolf->wall[2].width,
		&wolf->wall[2].height);
	wolf->wall[3].img = mlx_xpm_file_to_image(wolf->mlx, "texture/eagle.xpm", &wolf->wall[3].width,
		&wolf->wall[3].height);
	wolf->wall[4].img = mlx_xpm_file_to_image(wolf->mlx, "texture/vovan2.xpm", &wolf->wall[4].width,
		&wolf->wall[4].height);
	wolf->wall[5].img = mlx_xpm_file_to_image(wolf->mlx, "texture/wood.xpm", &wolf->wall[5].width,
		&wolf->wall[5].height);
	wolf->wall[6].img = mlx_xpm_file_to_image(wolf->mlx, "texture/ceiling_01.xpm", &wolf->wall[6].width,
		&wolf->wall[6].height); //celling
	wolf->wall[7].img = mlx_xpm_file_to_image(wolf->mlx, "texture/floor_01.xpm", &wolf->wall[7].width,
		&wolf->wall[7].height); //floor
	wolf->wall[8].img = mlx_xpm_file_to_image(wolf->mlx, "texture/door.xpm", &wolf->wall[8].width,
		&wolf->wall[8].height);   //door
}
