/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:10:13 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/16 14:59:16 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_mass(t_wolf *wolf)
{
	int		i;
	int		j;

	i = 0;
	while (wolf->map_tmp[i++] != NULL && wolf->map[i] != NULL)
	{
		j = -1;
		while (wolf->map_tmp[i][++j] != '\0' && wolf->map[i][j] != '\0')
			wolf->map[i][j] = wolf->map_tmp[i][j];
	}
}

void	cheats(int keycode, t_wolf *wolf)
{
	if (keycode == 31)
		wolf->ch = 1;
	if (keycode == 40)
		wolf->ch1 = 1;
	if (keycode == 21)
		wolf->ch2 = 1;
	if (keycode == 82 && wolf->ch == 1 && wolf->ch1 == 1 && wolf->ch2 == 1)
		restart(wolf, 40.5, 20.5, 0);
	if (keycode == 83 && wolf->ch == 1 && wolf->ch1 == 1 && wolf->ch2 == 1)
		restart(wolf, 8.5, 8.5, 1);
	if (keycode == 84 && wolf->ch == 1 && wolf->ch1 == 1 && wolf->ch2 == 1)
		restart(wolf, 29.5, 1.5, 2);
	if (keycode == 85 && wolf->ch == 1 && wolf->ch1 == 1 && wolf->ch2 == 1)
		restart(wolf, 40.5, 5.5, 3);
	if (keycode == 105 && wolf->ch == 1 && wolf->ch1 == 1 && wolf->ch2 == 1)
		wolf->men.menu = 2;
}

void	cheats2(int keycode, t_wolf *wolf)
{
	if (keycode == 86 && chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '0')
		wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][CH_X] = ':';
	if (keycode == 87 && chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '0')
		wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][CH_X] = ';';
	if (keycode == 88 && chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '0')
		wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][CH_X] = '<';
	if (keycode == 89 && chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '0')
		wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][CH_X] = '=';
	if (keycode == 91 && chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '0')
		wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][CH_X] = '>';
	if (keycode == 92 && chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '0')
		wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][CH_X] = '?';
}

void	keys_norm(int keycode, t_wolf *wolf)
{
	if (keycode == 14)
	{
		if (chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == 'B')
			restart(wolf, 8.5, 8.5, 1);
		if (chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '9')
			wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][CH_X] = '+';
		if (chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '>')
		{
			if (wolf->vov != 5)
			{
				wolf->vov += 1;
				wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][CH_X] = '0';
			}
		}
		else if (chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '5')
		{
			if (wolf->lvl == 1 && wolf->vov == 5)
				restart(wolf, 29.5, 1.5, 2);
			else if (wolf->lvl == 2)
				wolf->men.menu = 2;
		}
	}
}

void	menu_norm(t_wolf *wolf)
{
	raycasting(wolf);
	ft_print_info(wolf);
}
