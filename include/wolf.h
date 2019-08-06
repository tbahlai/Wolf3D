/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:26:48 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/25 14:26:48 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdio.h>
# include "../lib/libft.h"
# include "mlx.h"
# include <math.h>

# define B_SIZE 65536
# define WID 	1920
# define HEIG	1200
# define FREE(x, y) free(x), free(y);
# define MENU(z) if (z == 1) menu(wolf);

typedef struct	s_mlx
{
	int			*data;
	void		*win;
	void		*init;
	void		*img;
	int			*img_ptr;
	int			bpp;
	int			sl;
	int			endian;
	void		*img2;
	int			*data2;
	int			bpp2;
	int			sl2;
	int			endian2;

}				t_mlx;

typedef struct	s_draw
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	double		x;
	double		cam_x;
	double		raydir_x;
	double		raydir_y;
	double		deltadist_x;
	double		deltadist_y;
	double		sidedist_x;
	double		sidedist_y;
	double		perwalldist;
	double		raypos_x;
	double		raypos_y;
	double		rs;
	double		ms;
	double		d;
	double		weight;
	double		x_wall;
	int			texture;
	int			id;
	int			text_x;
	int			text_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			drawstart;
	int			drawend;
	int			lineheight;
	int			color;
	int			sky;
	int			skybox;
	int			swit4;
	int			shadow;
	int			menu;

}				t_draw;

typedef struct	s_move
{
	int			right;
	int			left;
	int			up;
	int			down;
	int			back;
	int			forward;
}				t_move;

typedef struct	s_map
{
	int			**value;
	int			width;
	int			height;
	char		*name_map;
}				t_map;

typedef struct	s_wolf
{
	t_mlx		text[8];
	t_mlx		text_sky[1];
	t_draw		draw;
	t_map		map;
	t_mlx		mlx;
	t_move		move;
}				t_wolf;

void			where_i_am(t_wolf *wolf);
void			menu(t_wolf *wolf);
void			draw_skybox(t_wolf *wolf, int x);
void			pixel(t_wolf *wolf, int x);
void			error(int flag);
void			draw_sky(t_wolf *wolf);
void			initial_texture(t_wolf *wolf);
void			floor_casting(t_wolf *wolf, int x);
void			initial_texture(t_wolf *wolf);
void			draw_wall(t_wolf *wolf, int x);
int				move(t_wolf *wolf);
void			raycasting(t_wolf *wolf);
int				valid_file(t_wolf *wolf, char **av);
int				main(int ac, char **av);
int				keyss_hook(int keycode, t_wolf *wolf);
int				key_reset(int keycode, t_wolf *wolf);
#endif
