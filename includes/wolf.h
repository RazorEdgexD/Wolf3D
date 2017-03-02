/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:01:01 by aosobliv          #+#    #+#             */
/*   Updated: 2017/02/27 19:01:22 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define WIN_X 1024
# define WIN_Y 768
# define THRUE_CHAR(c) ((((c) >= '0') && ((c) <= '9')) ? 1 : 0)


# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"
# include <fcntl.h>

# include <stdio.h>

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_draw
{
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				error;
	int				error2;
	struct s_point	point1;
	struct s_point	point2;
}					t_draw;

typedef struct		s_plr
{
	t_point			pos;
	t_point			dir;
	t_point			plane;
}					t_plr;

typedef struct		s_ray
{
	t_point			pos;
	t_point			dir;
	t_point			camera;
}					t_ray;

typedef struct		s_map
{
	int				map_x;
	int				map_y;
	t_point			sidedist;
	t_point			deltadist;
	double			perpwalldist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_map;

typedef struct		s_wolf
{
	void			*win;
	void			*mlx;
	void			*image;

	int				color;
	int				map_len;
	int				map_height;
	int				i;

	double			time;
	double			old_time;

	char			*program_name;
	char			**map;
	t_draw			draw;
	t_plr			plr;
	t_ray			ray;
	t_map			mapa;
}					t_wolf;

void				ft_error(int code);
void				read_map(char *map, t_wolf *wolf);
int					ft_hooks(t_wolf *wolf);
void				raycasting(t_wolf *wolf);
void				ft_draw_line(t_wolf *wolf, t_draw *draw, t_point *t0,
						t_point *t1);
void				draw_line2(t_wolf *wolf, int x, int y0, int y1);

#endif
