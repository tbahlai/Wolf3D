/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:10:17 by tbahlai           #+#    #+#             */
/*   Updated: 2019/03/02 18:10:18 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		rotation_left_right(t_wolf *wolf, double angle)
{
	double	old_dir;
	double	old_plane;

	old_dir = wolf->draw.dir_x;
	old_plane = wolf->draw.plane_x;
	wolf->draw.dir_x = wolf->draw.dir_x * cos(angle) - wolf->draw.dir_y * \
		sin(angle);
	wolf->draw.dir_y = old_dir * sin(angle) + wolf->draw.dir_y * \
		cos(angle);
	wolf->draw.plane_x = wolf->draw.plane_x * cos(angle) - \
		wolf->draw.plane_y * sin(angle);
	wolf->draw.plane_y = old_plane * sin(angle) + wolf->draw.plane_y * \
		cos(angle);
}

int			move(t_wolf *wolf)
{
	if (wolf->move.right == 1)
		rotation_left_right(wolf, -wolf->draw.rs);
	if (wolf->move.left == 1)
		rotation_left_right(wolf, wolf->draw.rs);
	if (wolf->move.forward == 1)
	{
		if (!wolf->map.value[(int)(wolf->draw.pos_x + wolf->draw.dir_x * 2 * \
				wolf->draw.ms)][(int)(wolf->draw.pos_y)])
			wolf->draw.pos_x += wolf->draw.dir_x * wolf->draw.ms;
		if (!wolf->map.value[(int)(wolf->draw.pos_x)][(int)(wolf->draw.pos_y \
				+ wolf->draw.dir_y * 2 * wolf->draw.ms)])
			wolf->draw.pos_y += wolf->draw.dir_y * wolf->draw.ms;
	}
	if (wolf->move.back == 1)
	{
		if (wolf->map.value[(int)(wolf->draw.pos_x - wolf->draw.dir_x * 2 \
				* wolf->draw.ms)][(int)(wolf->draw.pos_y)] == 0)
			wolf->draw.pos_x -= wolf->draw.dir_x * wolf->draw.ms;
		if (wolf->map.value[(int)(wolf->draw.pos_x)][(int)(wolf->draw.pos_y \
				- wolf->draw.dir_y * 2 * wolf->draw.ms)] == 0)
			wolf->draw.pos_y -= wolf->draw.dir_y * wolf->draw.ms;
	}
	raycasting(wolf);
	MENU(wolf->draw.menu);
	return (0);
}
