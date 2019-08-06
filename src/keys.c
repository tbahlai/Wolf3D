/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:45:59 by tbahlai           #+#    #+#             */
/*   Updated: 2019/03/02 18:45:59 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int			keys1_hook(int keycode, t_wolf *wolf)
{
	if (keycode == 36)
	{
		wolf->draw.sky = 0;
		wolf->draw.texture = 0;
		wolf->draw.skybox = 0;
	}
	else if (keycode == 257 || keycode == 258)
	{
		wolf->draw.rs = 0.1;
		wolf->draw.ms = 0.1;
	}
	else if (keycode == 82)
	{
		wolf->draw.texture = 0;
		wolf->draw.sky = 0;
		wolf->draw.skybox = 1;
	}
	else if (keycode == 87)
		wolf->draw.shadow = 1;
	else if (keycode == 88)
		wolf->draw.shadow = 0;
	return (0);
}

int			keyss_hook(int keycode, t_wolf *wolf)
{
	if (keycode == 124 || keycode == 2)
		wolf->move.right = 1;
	else if (keycode == 123 || keycode == 0)
		wolf->move.left = 1;
	else if (keycode == 125 || keycode == 1)
		wolf->move.back = 1;
	else if (keycode == 126 || keycode == 13)
		wolf->move.forward = 1;
	else if (keycode == 53)
		error(7);
	else if (keycode == 49)
	{
		wolf->draw.sky = 1;
		wolf->draw.texture = 1;
		wolf->draw.skybox = 0;
	}
	else if (keycode == 46)
	{
		if (wolf->draw.menu == 0)
			wolf->draw.menu = 1;
		else
			wolf->draw.menu = 0;
	}
	keys1_hook(keycode, wolf);
	return (0);
}

int			key_reset(int keycode, t_wolf *wolf)
{
	if (keycode == 124 || keycode == 2)
		wolf->move.right = 0;
	else if (keycode == 123 || keycode == 0)
		wolf->move.left = 0;
	else if (keycode == 125 || keycode == 1)
		wolf->move.back = 0;
	else if (keycode == 126 || keycode == 13)
		wolf->move.forward = 0;
	else if (keycode == 257 || keycode == 258)
	{
		wolf->draw.rs = 0.05;
		wolf->draw.ms = 0.05;
	}
	return (0);
}
