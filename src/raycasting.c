/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:59:10 by tbahlai           #+#    #+#             */
/*   Updated: 2019/03/02 11:59:10 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		perform_dda(t_wolf *wolf)
{
	wolf->draw.hit = 0;
	while (wolf->draw.hit == 0)
	{
		if (wolf->draw.sidedist_x < wolf->draw.sidedist_y)
		{
			wolf->draw.sidedist_x += wolf->draw.deltadist_x;
			wolf->draw.map_x += wolf->draw.step_x;
			wolf->draw.side = 0;
		}
		else
		{
			wolf->draw.sidedist_y += wolf->draw.deltadist_y;
			wolf->draw.map_y += wolf->draw.step_y;
			wolf->draw.side = 1;
		}
		if (wolf->map.value[wolf->draw.map_x][wolf->draw.map_y] > 0)
			wolf->draw.hit = 1;
	}
}

void		calc(t_wolf *wolf, int flag)
{
	if (flag == 1)
	{
		wolf->draw.step_x = -1;
		wolf->draw.sidedist_x = (wolf->draw.raypos_x - wolf->draw.map_x) \
			* wolf->draw.deltadist_x;
	}
	if (flag == 2)
	{
		wolf->draw.step_x = 1;
		wolf->draw.sidedist_x = (wolf->draw.map_x + 1.0 - wolf->draw.raypos_x) \
			* wolf->draw.deltadist_x;
	}
}

void		length_of_ray(t_wolf *wolf)
{
	wolf->draw.deltadist_x = sqrt(1 + (wolf->draw.raydir_y * \
		wolf->draw.raydir_y) / (wolf->draw.raydir_x * wolf->draw.raydir_x));
	wolf->draw.deltadist_y = sqrt(1 + (wolf->draw.raydir_x * \
		wolf->draw.raydir_x) / (wolf->draw.raydir_y * wolf->draw.raydir_y));
	if (wolf->draw.raydir_x < 0)
		calc(wolf, 1);
	else
		calc(wolf, 2);
	if (wolf->draw.raydir_y < 0)
	{
		wolf->draw.step_y = -1;
		wolf->draw.sidedist_y = (wolf->draw.raypos_y - wolf->draw.map_y) \
		* wolf->draw.deltadist_y;
	}
	else
	{
		wolf->draw.step_y = 1;
		wolf->draw.sidedist_y = (wolf->draw.map_y + 1.0 - \
			wolf->draw.raypos_y) * wolf->draw.deltadist_y;
	}
}

void		calculations(t_wolf *wolf)
{
	wolf->draw.cam_x = 2 * wolf->draw.x / WID - 1;
	wolf->draw.raydir_x = wolf->draw.dir_x + wolf->draw.plane_x * \
		wolf->draw.cam_x;
	wolf->draw.raydir_y = wolf->draw.dir_y + wolf->draw.plane_y * \
		wolf->draw.cam_x;
	wolf->draw.raypos_x = wolf->draw.pos_x;
	wolf->draw.raypos_y = wolf->draw.pos_y;
	wolf->draw.map_x = wolf->draw.raypos_x;
	wolf->draw.map_y = wolf->draw.raypos_y;
	length_of_ray(wolf);
	perform_dda(wolf);
	if (wolf->draw.side == 0)
		wolf->draw.perwalldist = (wolf->draw.map_x - wolf->draw.raypos_x + \
			(1 - wolf->draw.step_x) / 2) / wolf->draw.raydir_x;
	else
		wolf->draw.perwalldist = (wolf->draw.map_y - wolf->draw.raypos_y + \
			(1 - wolf->draw.step_y) / 2) / wolf->draw.raydir_y;
}

void		raycasting(t_wolf *wolf)
{
	ft_bzero(wolf->mlx.img_ptr, WID * HEIG * 4);
	wolf->draw.x = 0;
	while (wolf->draw.x < WID)
	{
		calculations(wolf);
		wolf->draw.lineheight = (int)(HEIG / wolf->draw.perwalldist);
		wolf->draw.drawstart = -wolf->draw.lineheight / 2 + HEIG / 2;
		wolf->draw.drawend = wolf->draw.lineheight / 2 + HEIG / 2;
		if (wolf->draw.drawstart < 0)
			wolf->draw.drawstart = 0;
		if (wolf->draw.drawend >= HEIG)
			wolf->draw.drawend = HEIG - 1;
		if (wolf->draw.side == 1)
			wolf->draw.color = 13215487;
		else
			wolf->draw.color = 9532102;
		pixel(wolf, wolf->draw.x);
		if (wolf->draw.texture == 1 || wolf->draw.skybox == 1)
			draw_wall(wolf, wolf->draw.x);
		if (wolf->draw.skybox == 1)
			draw_skybox(wolf, wolf->draw.x);
		wolf->draw.x++;
	}
	mlx_put_image_to_window(wolf->mlx.init, wolf->mlx.win, \
		wolf->mlx.img, 0, 0);
}
