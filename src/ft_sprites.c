/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:21:24 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/13 20:13:40 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_sprites(t_wolf *wolf, int x)
{
	int	i;
	int	y;
	int	d;
	wolf->sprite[0].pos.x = 1;
	wolf->sprite[0].pos.y = 2;
	wolf->sprite[0].text_num = 0;
	wolf->sprite[1].pos.x = 4;
	wolf->sprite[1].pos.y = 4;
	wolf->sprite[1].text_num = 0;
	wolf->sprite[2].pos.x = 20;
	wolf->sprite[2].pos.y = 20;
	wolf->sprite[2].text_num = 0;
	wolf->sprite[3].pos.x = 5;
	wolf->sprite[3].pos.y = 5;
	wolf->sprite[3].text_num = 0;
	wolf->sprite[4].pos.x = 10;
	wolf->sprite[4].pos.y = 10;
	wolf->sprite[4].text_num = 0;
	i = -1;
	while (++i < SPR)
	{
		wolf->spriteorder[i] = i;
		wolf->spritedistance[i] = ((PLR_POS_X - wolf->sprite[i].pos.x) * (PLR_POS_X
			- wolf->sprite[i].pos.x) + (PLR_POS_Y - wolf->sprite[i].pos.y) * (PLR_POS_Y -
				wolf->sprite[i].pos.y));
	}
	i = -1;
	sort(wolf->spriteorder, wolf->spritedistance);
	while (++i < SPR)
	{
		wolf->sprite_x = wolf->sprite[i].pos.x - PLR_POS_X;
		wolf->sprite_y = wolf->sprite[i].pos.y - PLR_POS_Y;
		wolf->intdev = 1. / (PLR_PL_X * PLR_DIR_Y - PLR_DIR_X * PLR_PL_Y);
		wolf->trans.x = wolf->intdev * (PLR_DIR_Y * wolf->sprite_x - PLR_DIR_X * wolf->sprite_y);
		wolf->trans.y = wolf->intdev * (-PLR_PL_Y * wolf->sprite_x + PLR_PL_X * wolf->sprite_y);
		wolf->s_s_x = (int)(WIN_X / 2) * (1 + wolf->trans.x / wolf->trans.y);
		wolf->spr_hei = fabs((int)WIN_Y / wolf->trans.y);
		wolf->dr_s_y = -wolf->spr_hei / 2 + WIN_Y / 2;
		if (wolf->dr_s_y < 0)
			wolf->dr_s_y = 0;
		wolf->dr_e_y = wolf->spr_hei / 2 + WIN_Y / 2;
		if (wolf->dr_e_y >= WIN_Y)
			wolf->dr_e_y = WIN_Y - 1;

		wolf->spr_wid = fabs((int)WIN_Y / wolf->trans.y);
		wolf->dr_s_x = -wolf->spr_wid / 2 + wolf->s_s_x;
		if (wolf->dr_s_x < 0)
			wolf->dr_s_x = 0;
		wolf->dr_e_x = wolf->spr_wid / 2 + wolf->s_s_x;
		if (wolf->dr_s_x >= WIN_X)
			wolf->dr_s_x = WIN_X - 1;
		wolf->stripe = -1;
		while (++wolf->stripe < wolf->dr_s_x)
		{
			wolf->text_x = (int)(256 * (wolf->stripe - (-wolf->spr_wid / 2 + wolf->s_s_x)) * TEX_X / wolf->spr_wid) / 256;
			if (wolf->trans.y > 0 && wolf->stripe > 0 && wolf->stripe < WIN_X)
			{
				y = wolf->dr_s_y;
				while (y < wolf->dr_e_y)
				{
					d = (y << 8) - (WIN_Y << 7) + (wolf->spr_hei << 7);
					wolf->text_y = ((d * TEX_X) / wolf->spr_hei) << 8;
					wolf->color = ft_image_pixel_get(wolf->text_x, wolf->text_y,
						&wolf->spr[0], wolf);
					ft_image_pixel_put(wolf, x, y, wolf->color);
					y++;
				}
			}
		}

	}
}
