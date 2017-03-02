/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:34:16 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/01 15:34:18 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error(int code)
{
	if (code == 1)
	{
		ft_putendl("Wrong Map Length or Height...");
		exit(1);
	}
	if (code == 2)
	{
		ft_putendl("Wrong Char...");
		exit(2);
	}
	if (code == 3)
	{
		ft_putendl("No Walls on side lines || All Char Walls...");
		exit(3);
	}
	if (code == 4)
	{
		ft_putendl("Cannot open file...\n(Usage ./wolf3d [map_name].wolf)");
		exit(4);
	}
	if (code == 5)
	{
		ft_putendl("Usage ./wolf3d [map_name].wolf | Start");
		exit(5);
	}
}

void	ft_image_pixel_put(t_wolf *wolf, int x, int y, int rgb)
{
	int				bpp;
	int				sl;
	int				en;
	char			*image;
	unsigned int	tmp;

	image = mlx_get_data_addr(wolf->image, &bpp, &sl, &en);
	tmp = (mlx_get_color_value(wolf->mlx, rgb));
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
		ft_memcpy((void *)(image + y * WIN_X * (bpp / 8)) + x * (bpp / 8),
			(void *)&tmp, 4);
}

void	count_delta(t_point *t0, t_point *t1, t_draw *draw)
{
	draw->deltax = fabs(t1->x - t0->x);
	draw->deltay = fabs(t1->y - t0->y);
	draw->signx = t1->x >= t0->x ? 1 : -1;
	draw->signy = t1->y >= t0->y ? 1 : -1;
	draw->error = draw->deltax - draw->deltay;
	draw->error2 = 2 * draw->error;
}

void	ft_draw_line(t_wolf *wolf, t_draw *draw, t_point *t0, t_point *t1)
{
	int		x0;
	int		y0;

	x0 = (int)t0->x;
	y0 = (int)t0->y;
	count_delta(t0, t1, draw);
	ft_image_pixel_put(wolf, t1->x, t1->y, wolf->color);
	while (t1->x != t0->x || t1->y != t0->y)
	{
		ft_image_pixel_put(wolf, t0->x, t0->y, wolf->color);
		draw->error2 = draw->error * 2;
		if (draw->error2 > -draw->deltay)
		{
			draw->error -= draw->deltay;
			t0->x += draw->signx;
		}
		if (draw->error2 < draw->deltax)
		{
			draw->error += draw->deltax;
			t0->y += draw->signy;
		}
	}
	t0->x = x0;
	t0->y = y0;
}

void	draw_line2(t_wolf *wolf, int x, int y0, int y1)
{
	while (y0 != y1)
	{
		ft_image_pixel_put(wolf, x, y0, wolf->color);
		y0++;
	}
}
