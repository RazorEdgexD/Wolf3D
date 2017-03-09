/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:32:13 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/09 21:22:25 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		close_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		keys_release(int keycode, t_wolf *wolf)
{
	(keycode == 257) ? wolf->key.shf = 0 : 1488;
	(keycode == 13) ? wolf->key.w = 0 : 1488;
	(keycode == 1) ? wolf->key.s = 0 : 1488;
	(keycode == 0) ? wolf->key.a = 0 : 1488;
	(keycode == 2) ? wolf->key.d = 0 : 1488;
	return (0);
}

int		keys_press(int keycode, t_wolf *wolf)
{
	if (keycode == 14)
	{
		if (wolf->map[MAP_Y][MAP_X] == '9')
			wolf->map[MAP_Y][MAP_X] = '0';
	}
	if (keycode == 12)
	{
		if (wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][(int)(PLR_POS_X +
			PLR_DIR_X)] == '0')
			wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][(int)(PLR_POS_X + 2 *
				PLR_DIR_X)] = '9';
	}
	(keycode == 257) ? wolf->key.shf = 1 : 1488;
	(keycode == 53) ? exit(777) : 1488;
	(keycode == 13) ? wolf->key.w = 1 : 1488;
	(keycode == 1) ? wolf->key.s = 1 : 1488;
	(keycode == 0) ? wolf->key.a = 1 : 1488;
	(keycode == 2) ? wolf->key.d = 1 : 1488;
	return (0);
}

int		ft_hooks(t_wolf *wolf)
{
	(wolf->key.shf == 1) ? wolf->ms_k = 4.75 : 1488;
	(wolf->key.shf == 0) ? wolf->ms_k = 3.5 : 1488;
	(wolf->key.a == 1) ? rotate_left(wolf) : 1488;
	(wolf->key.d == 1) ? rotate_right(wolf) : 1488;
	(wolf->key.w == 1) ? move_forward(wolf) : 1488;
	(wolf->key.s == 1) ? move_backward(wolf) : 1488;
	mlx_hook(wolf->win, 2, 1, keys_press, wolf);
	mlx_hook(wolf->win, 3, 2, keys_release, wolf);
	mlx_hook(wolf->win, 17, 0L, close_x, wolf);
	raycasting(wolf);
	ft_print_info(wolf);
	return (0);
}
