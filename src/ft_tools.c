/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:34:16 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/09 20:51:26 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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

int		ft_image_pixel_get(int x, int y, t_img *img, t_wolf *wolf)
{
	int				bpp;
	int				sl;
	int				en;
	char			*image;
	unsigned int	tmp;

	tmp = 0;
	wolf->color = 0;
	image = mlx_get_data_addr(img->img, &bpp, &sl, &en);
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
		ft_memcpy((void *)(&tmp), (void *)((image + y * img->width * (bpp / 8))
			+ x * (bpp / 8)), 4);
	return (tmp);
}

void	draw_texture(t_wolf *wolf, int x, int y0, int y1)
{
	int	d;

	d = 0;
	while (y0 != y1)
	{
		d = (y0 << 8) - (WIN_Y << 7) + (LINE_H << 7);
		wolf->text_y = ((d * TEX_Y) / LINE_H) >> 8;
		wolf->color = ft_image_pixel_get(wolf->text_x, wolf->text_y,
			&wolf->wall[wolf->tex_num], wolf);
		if (MAP_SIDE == 1)
			wolf->color = (wolf->color >> 1) & 8355711;
		ft_image_pixel_put(wolf, x, y0, wolf->color);
		y0++;
	}
}

void	pixel_on_floor(t_wolf *wolf, int x, int y)
{
	wolf->color = ft_image_pixel_get(wolf->f_text_x, wolf->f_text_y,
		&wolf->wall[7], wolf);
	ft_image_pixel_put(wolf, x, y, wolf->color);
	wolf->color = ft_image_pixel_get(wolf->f_text_x, wolf->f_text_y,
		&wolf->wall[6], wolf);
	ft_image_pixel_put(wolf, x, WIN_Y - y, wolf->color);
}

void	draw_floor_sel(t_wolf *wolf, int x)
{
	double	cur_dis;
	double	cur_fl_x;
	double	cur_fl_y;
	double	weght;
	int		y;

	if (DRAW_END < WIN_Y)
		y = DRAW_END;
	else
		return ;
	cur_dis = 0;
	cur_fl_x = 0;
	cur_fl_y = 0;
	while (++y != WIN_Y)
	{
		cur_dis = WIN_Y / (2. * y - WIN_Y);
		weght = (cur_dis - wolf->dist_plr) / (wolf->dist_wall - wolf->dist_plr);
		cur_fl_x = weght * wolf->f_wallx + (1. - weght) * PLR_POS_X;
		cur_fl_y = weght * wolf->f_wally + (1. - weght) * PLR_POS_Y;
		wolf->f_text_x = ((int)(cur_fl_x * TEX_X)) % TEX_X;
		wolf->f_text_y = ((int)(cur_fl_y * TEX_Y)) % TEX_Y;
		pixel_on_floor(wolf, x, y);
	}
}
