/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:01:01 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/13 20:02:56 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define WIN_X 1024
# define WIN_Y 768
# define TEX_X 64
# define TEX_Y 64
# define SPR 5
# define THRUE_CHAR(c) (((((c) >= '0') && ((c) <= '9')) || c == 'p') ? 1 : 0)

# define MAP_X	wolf->mapa.map_x
# define MAP_Y	wolf->mapa.map_y
# define STEP_X wolf->mapa.step_x
# define STEP_Y wolf->mapa.step_y
# define LINE_H wolf->mapa.line_height
# define D_P_WALL wolf->mapa.perpwalldist
# define SIDE_DIS_X wolf->mapa.sidedist.x
# define SIDE_DIS_Y wolf->mapa.sidedist.y
# define DELT_DIS_X wolf->mapa.deltadist.x
# define DELT_DIS_Y wolf->mapa.deltadist.y
# define DRAW_START wolf->mapa.draw_start
# define DRAW_END wolf->mapa.draw_end
# define RAY_POS_X wolf->ray.pos.x
# define RAY_POS_Y wolf->ray.pos.y
# define RAY_DIR_X wolf->ray.dir.x
# define RAY_DIR_Y wolf->ray.dir.y
# define PLR_POS_X wolf->plr.pos.x
# define PLR_POS_Y wolf->plr.pos.y
# define PLR_DIR_X wolf->plr.dir.x
# define PLR_DIR_Y wolf->plr.dir.y
# define MS wolf->move_speed
# define RS wolf->rot_speed
# define PLR_PL_X wolf->plr.plane.x
# define PLR_PL_Y wolf->plr.plane.y
# define MAP_SIDE wolf->mapa.side

# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"
# include <fcntl.h>
# include <time.h>
# include <pthread.h>

#include <stdio.h>

typedef unsigned char	t_bool;

typedef struct		s_menu
{
	int				flag;
	int				menu;
}					t_menu;

typedef struct		s_key
{
	int				a;
	int				s;
	int				d;
	int				w;
	int				shf;
}					t_key;

typedef struct		s_img
{
	int				width;
	int				height;
	void			*img;
}					t_img;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_spr
{
	t_point			pos;
	int				text_num;
}					t_spr;

typedef struct		s_plr
{
	t_point			pos;
	t_point			ch_pos;
	t_point			f_pos;
	t_point			dir;
	t_point			plane;
	t_point			old_dir;
	t_point			old_plane;
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
	int				start;
	int				tex_num;
	int				text_x;
	int				text_y;
	int				f_text_x;
	int				f_text_y;
	int				s_s_x;
	int				spr_hei;
	int				spr_wid;
	int				dr_s_y;
	int				dr_e_y;
	int				dr_s_x;
	int				dr_e_x;
	int				stripe;

	int				spriteorder[SPR];
	int				mus;
	int				y;
	int				xocolor;
	int				ycolor;
	int				xycolor;

	double			spritedistance[SPR];
	double			sprite_x;
	double			sprite_y;
	double			dist_wall;
	double			dist_plr;
	double			dist_cur;
	double			time;
	double			old_time;
	double			frametime;
	double			wallx;
	double			f_wallx;
	double			f_wally;
	double			move_speed;
	double			ms_k;
	double			rot_speed;
	double			intdev;

	char			**map_tmp;
	char			*program_name;
	char			**map;
	char			buffer[WIN_X][WIN_Y];

	pthread_t		tread[2];
	t_plr			plr;
	t_ray			ray;
	t_map			mapa;
	t_point			trans;
	t_menu			men;
	t_key			key;
	t_img			*wall;
	t_img			*menu;
	t_img			*spr;
	t_spr			sprite[SPR];
}					t_wolf;

void				*music(void *lol);
void 				sort(int *order, double *dist);
void				ft_error(int code);
void				read_map(char *map, t_wolf *wolf);
int					ft_hooks(t_wolf *wolf);
void				init_player(t_wolf *wolf);
void				init_wolf(t_wolf *wolf);
char				**make_arr(t_wolf *wolf, int fd);
void				move_forward(t_wolf *wolf);
void				move_backward(t_wolf *wolf);
void				rotate_left(t_wolf *wolf);
void				rotate_right(t_wolf *wolf);
void				make_texture(t_wolf *wolf);
void				raycasting(t_wolf *wolf);
void				init_camera(t_wolf *wolf);
void				load_texture(t_wolf *wolf);
void				restart(t_wolf *wolf);
void				free_mass(t_wolf *wolf);
int					close_x(void *par);
void				ft_image_pixel_put(t_wolf *wolf, int x, int y, int rgb);
int					ft_image_pixel_get(int x, int y, t_img *img, t_wolf *wolf);
char				chmo(t_wolf *wolf, int y, int x);
void				draw_floor(t_wolf *wolf, int x, int y);
void				draw_floor_sel(t_wolf *wolf, int x);
void				draw_sprites(t_wolf *wolf, int x);
void				draw_line(t_wolf *wolf, int x, int y0, int y1);
void				draw_texture(t_wolf *wolf, int x, int y0, int y1);
void				ft_print_info(t_wolf *wolf);

#endif
