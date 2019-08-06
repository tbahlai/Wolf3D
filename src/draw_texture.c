/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:33:12 by tbahlai           #+#    #+#             */
/*   Updated: 2019/03/03 17:33:13 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		draw_skybox(t_wolf *wolf, int x)
{
	int y;

	y = -1;
	while (++y < wolf->draw.drawstart)
	{
		*(wolf->mlx.img_ptr + WID * y + x) = \
		wolf->text_sky[0].data[WID * y + x];
	}
}

void		pixel(t_wolf *wolf, int x)
{
	int y;

	y = -1;
	if (wolf->draw.x < WID && y < HEIG)
	{
		while (++y < wolf->draw.drawstart)
			*(wolf->mlx.img_ptr + WID * y + x) = 8421504;
		y--;
		while (++y < wolf->draw.drawend)
			*(wolf->mlx.img_ptr + WID * y + x) = wolf->draw.color;
		y--;
		while (++y < HEIG)
			*(wolf->mlx.img_ptr + WID * y + x) = 8675663;
	}
}

void		which_side(t_wolf *wolf, int x, int y, int flag)
{
	int color;

	if (flag == 1)
	{
		color = *(wolf->text[wolf->draw.id].data + (wolf->draw.text_y * \
			64 + wolf->draw.text_x));
		*(wolf->mlx.img_ptr + (y * WID + x)) = \
			(wolf->draw.shadow == 1) ? (color >> 1) & 8355711 : color;
	}
	else if (flag == 2)
	{
		color = *(wolf->text[wolf->draw.id + 2].data + (wolf->draw.text_y * \
			64 + wolf->draw.text_x));
		*(wolf->mlx.img_ptr + (y * WID + x)) = \
			(wolf->draw.shadow == 1) ? (color >> 1) & 8355711 : color;
	}
	else if (flag == 3)
	{
		color = *(wolf->text[wolf->draw.id + 3].data + (wolf->draw.text_y * \
			64 + wolf->draw.text_x));
		*(wolf->mlx.img_ptr + (y * WID + x)) = \
			(wolf->draw.shadow == 1) ? (color >> 1) & 8355711 : color;
	}
}

void		draw_texture_wall(t_wolf *wolf, int x, int start, int end)
{
	int		y;
	int		d;
	int		color;

	y = start - 1;
	while (++y < end)
	{
		d = y * 256 - HEIG * 128 + wolf->draw.lineheight * 128;
		wolf->draw.text_y = ((d * 64) / wolf->draw.lineheight) / 256;
		if (wolf->draw.side == 1 && wolf->draw.raydir_y < 0)
			which_side(wolf, x, y, 1);
		else if (wolf->draw.side == 1 && wolf->draw.raydir_y > 0)
			which_side(wolf, x, y, 2);
		else if (wolf->draw.side == 0 && wolf->draw.raydir_x < 0)
			which_side(wolf, x, y, 3);
		else if (wolf->draw.side == 0 && wolf->draw.raydir_x > 0)
		{
			color = *(wolf->text[wolf->draw.id + 1].data + \
				(wolf->draw.text_y * 64 + wolf->draw.text_x));
			*(wolf->mlx.img_ptr + (y * WID + x)) = (wolf->draw.shadow == 1) \
				? (color >> 1) & 8355711 : color;
		}
	}
}

void		draw_wall(t_wolf *wolf, int x)
{
	wolf->draw.id = wolf->map.value[wolf->draw.map_x][wolf->draw.map_y];
	if (wolf->draw.id + 4 >= 7)
		wolf->draw.id = 1;
	if (wolf->draw.side == 0)
		wolf->draw.x_wall = wolf->draw.raypos_y + wolf->draw.perwalldist * \
		wolf->draw.raydir_y;
	else
		wolf->draw.x_wall = wolf->draw.raypos_x + wolf->draw.perwalldist * \
		wolf->draw.raydir_x;
	wolf->draw.x_wall -= (int)wolf->draw.x_wall;
	wolf->draw.text_x = (int)(wolf->draw.x_wall * 64.0);
	if (wolf->draw.side == 0 && wolf->draw.raydir_x > 0)
		wolf->draw.text_x = 64 - wolf->draw.text_x - 1;
	if (wolf->draw.side == 1 && wolf->draw.raydir_y < 0)
		wolf->draw.text_x = 64 - wolf->draw.text_x - 1;
	draw_texture_wall(wolf, x, wolf->draw.drawstart, wolf->draw.drawend);
	floor_casting(wolf, x);
}
