/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:32:13 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/16 15:00:13 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		keys_release(int keycode, t_wolf *wolf)
{
	(keycode == 257) ? wolf->key.shf = 0 : 1488;
	(keycode == 13) ? wolf->key.w = 0 : 1488;
	(keycode == 1) ? wolf->key.s = 0 : 1488;
	(keycode == 0) ? wolf->key.a = 0 : 1488;
	(keycode == 2) ? wolf->key.d = 0 : 1488;
	(keycode == 123) ? wolf->key.l = 0 : 1488;
	(keycode == 124) ? wolf->key.r = 0 : 1488;
	return (0);
}

int		keys_press(int keycode, t_wolf *wolf)
{
	cheats(keycode, wolf);
	cheats2(keycode, wolf);
	(keycode == 67) ? exit(333) : 1337;
	keys_norm(keycode, wolf);
	if (keycode == 12)
	{
		if (chmo(wolf, (int)(PLR_POS_Y + PLR_DIR_Y), CH_X) == '+')
			wolf->map[(int)(PLR_POS_Y + PLR_DIR_Y)][CH_X] = '9';
	}
	(keycode == 257) ? wolf->key.shf = 1 : 1488;
	if (keycode == 53)
		wolf->men.menu = 1;
	(keycode == 13) ? wolf->key.w = 1 : 1488;
	(keycode == 1) ? wolf->key.s = 1 : 1488;
	(keycode == 0) ? wolf->key.a = 1 : 1488;
	(keycode == 2) ? wolf->key.d = 1 : 1488;
	(keycode == 123) ? wolf->key.l = 1 : 1488;
	(keycode == 124) ? wolf->key.r = 1 : 1488;
	return (0);
}

int		keys_menu(int key, t_wolf *wolf)
{
	(key == 67) ? exit(333) : 1337;
	if (key == 53)
		wolf->men.menu = 0;
	if (key == 125 && wolf->men.flag < 2)
		wolf->men.flag += 1;
	if (key == 126 && wolf->men.flag > 0)
		wolf->men.flag -= 1;
	if (key == 36 && wolf->men.flag == 0)
		restart(wolf, 40.5, 20.5, 0);
	if (key == 36 && wolf->men.flag == 1)
		ft_putendl("ABTOP Razorywka");
	if (key == 36 && wolf->men.flag == 2)
		exit(777);
	return (1);
}

int		ft_hooks(t_wolf *wolf)
{
	(wolf->key.shf == 1) ? wolf->ms_k = 3.8 : 1488;
	(wolf->key.shf == 0) ? wolf->ms_k = 2.5 : 1488;
	(wolf->key.l == 1) ? rotate_left(wolf) : 1488;
	(wolf->key.r == 1) ? rotate_right(wolf) : 1488;
	(wolf->key.a == 1) ? move_left_right(wolf, 1) : 1488;
	(wolf->key.d == 1) ? move_left_right(wolf, 2) : 1488;
	(wolf->key.w == 1) ? move_forward_back(wolf, 1) : 1488;
	(wolf->key.s == 1) ? move_forward_back(wolf, 2) : 1488;
	mlx_hook(wolf->win, 2, 1, keys_press, wolf);
	mlx_hook(wolf->win, 3, 2, keys_release, wolf);
	mlx_hook(wolf->win, 17, 0L, close_x, wolf);
	if (wolf->men.menu == 0)
		menu_norm(wolf);
	if (wolf->men.menu == 1)
	{
		mlx_put_image_to_window(wolf->mlx, wolf->win,
			wolf->menu[wolf->men.flag].img, 0, 0);
		mlx_hook(wolf->win, 2, 1, keys_menu, wolf);
	}
	if (wolf->men.menu == 2)
	{
		mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->menu[3].img, 0, 0);
		mlx_hook(wolf->win, 2, 1, keys_menu, wolf);
	}
	return (0);
}
