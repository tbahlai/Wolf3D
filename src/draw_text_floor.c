/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:46:38 by tbahlai           #+#    #+#             */
/*   Updated: 2019/03/07 13:46:39 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		draw_floor(t_wolf *wolf, int x, double fl_x_wall, double fl_y_wall)
{
	int		color;
	int		y;
	int		flag;

	flag = (wolf->draw.skybox == 1) ? 512 : 64;
	wolf->draw.swit4 = (wolf->draw.skybox == 1) ? 7 : 0;
	y = wolf->draw.drawend;
	while (++y < HEIG)
	{
		wolf->draw.d = HEIG / (2.0 * y - HEIG);
		wolf->draw.weight = wolf->draw.d / (wolf->draw.perwalldist);
		wolf->draw.text_x = (int)((wolf->draw.weight * fl_x_wall + \
			(1.0 - wolf->draw.weight) * wolf->draw.pos_x) * flag) % flag;
		wolf->draw.text_y = (int)((wolf->draw.weight * fl_y_wall + \
			(1.0 - wolf->draw.weight) * wolf->draw.pos_y) * flag) % flag;
		color = *(wolf->text[wolf->draw.swit4].data + (wolf->draw.text_y * \
			flag + wolf->draw.text_x));
		*(wolf->mlx.img_ptr + (y * WID + x)) = color;
		if (wolf->draw.sky == 1)
		{
			color = *(wolf->text[5].data + (wolf->draw.text_y * 64 + \
				wolf->draw.text_x));
			*(wolf->mlx.img_ptr + ((HEIG - y) * WID + x)) = color * 0.5;
		}
	}
}

void		floor_casting(t_wolf *wolf, int x)
{
	double	fl_x_wall;
	double	fl_y_wall;

	if (wolf->draw.side == 0)
	{
		fl_y_wall = wolf->draw.map_y + wolf->draw.x_wall;
		if (wolf->draw.raydir_x > 0)
			fl_x_wall = wolf->draw.map_x;
		else
			fl_x_wall = wolf->draw.map_x + 1.0;
	}
	else
	{
		fl_x_wall = wolf->draw.map_x + wolf->draw.x_wall;
		if (wolf->draw.raydir_y > 0)
			fl_y_wall = wolf->draw.map_y;
		else
			fl_y_wall = wolf->draw.map_y + 1.0;
	}
	draw_floor(wolf, x, fl_x_wall, fl_y_wall);
}
