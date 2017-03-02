/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:32:13 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/02 15:32:14 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		close_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		keys(int keycode, t_wolf *wolf)
{
	wolf->color = 16777215;
	if (keycode == 53)
		exit(777);
	return (0);
}

int		ft_hooks(t_wolf *wolf)
{
	mlx_key_hook(wolf->win, keys, wolf);
	mlx_hook(wolf->win, 17, 0L, close_x, wolf);
	raycasting(wolf);
	return (0);
}
