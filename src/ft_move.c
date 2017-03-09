/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:41:15 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/06 16:37:32 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_forward(t_wolf *wolf)
{
	if (wolf->map[(int)PLR_POS_Y][(int)(PLR_POS_X + PLR_DIR_X * MS + PLR_DIR_X * 0.4)] <= '0')
		PLR_POS_X += PLR_DIR_X * MS;
	if (wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y * MS + PLR_DIR_Y * 0.4)][(int)PLR_POS_X] <= '0')
		PLR_POS_Y += PLR_DIR_Y * MS;
}

void	move_backward(t_wolf *wolf)
{
	if (wolf->map[(int)PLR_POS_Y][(int)(PLR_POS_X - PLR_DIR_X * MS - PLR_DIR_X
		* 0.4)] <= '0')
		PLR_POS_X -= PLR_DIR_X * MS;
	if (wolf->map[(int)(PLR_POS_Y - PLR_DIR_Y * MS - PLR_DIR_Y * 0.4)]
		[(int)PLR_POS_X] <= '0')
		PLR_POS_Y -= PLR_DIR_Y * MS;
}

void	rotate_left(t_wolf *wolf)
{
	wolf->plr.old_dir.x = PLR_DIR_X;
	PLR_DIR_X = PLR_DIR_X * cos(RS) - PLR_DIR_Y * sin(RS);
	PLR_DIR_Y = wolf->plr.old_dir.x * sin(RS) + PLR_DIR_Y * cos(RS);
	wolf->plr.old_plane.x = PLR_PL_X;
	PLR_PL_X = PLR_PL_X * cos(RS) - PLR_PL_Y * sin(RS);
	PLR_PL_Y = wolf->plr.old_plane.x * sin(RS) + PLR_PL_Y * cos(RS);
}

void	rotate_right(t_wolf *wolf)
{
	wolf->plr.old_dir.x = PLR_DIR_X;
	PLR_DIR_X = PLR_DIR_X * cos(-RS) - PLR_DIR_Y * sin(-RS);
	PLR_DIR_Y = wolf->plr.old_dir.x * sin(-RS) + PLR_DIR_Y * cos(-RS);
	wolf->plr.old_plane.x = PLR_PL_X;
	PLR_PL_X = PLR_PL_X * cos(-RS) - PLR_PL_Y * sin(-RS);
	PLR_PL_Y = wolf->plr.old_plane.x * sin(-RS) + PLR_PL_Y * cos(-RS);
}
