/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:42:28 by tbahlai           #+#    #+#             */
/*   Updated: 2019/03/10 15:42:29 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		make_square(t_wolf *wolf, int j, int i, int color)
{
	int	y;
	int	x;

	y = j;
	while (y++ <= (j + 15))
	{
		x = i;
		while (x++ <= (i + 15))
		{
			*(wolf->mlx.data2 + WID * y + x) = color;
		}
	}
}

void		transparent_img(t_wolf *wolf)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIG)
	{
		x = -1;
		while (++x < WID)
		{
			*(wolf->mlx.data2 + WID * y + x) = 0xFF000000;
		}
	}
}

void		where_i_am(t_wolf *wolf)
{
	int i;
	int j;
	int c;

	i = 0;
	transparent_img(wolf);
	c = (wolf->draw.texture == 1) ? 16777215 : 0;
	while (i < wolf->map.height)
	{
		j = 0;
		while (j < wolf->map.width)
		{
			if (wolf->map.value[i][j] != 0)
				make_square(wolf, (i + 1) * 15, (j + 1) * 15, c);
			if (wolf->map.value[i][j] == 0)
				make_square(wolf, (i + 1) * 15, (j + 1) * 15, 9539985);
			if ((int)wolf->draw.raypos_x == i && (int)wolf->draw.raypos_y == j)
				make_square(wolf, (i + 1) * 15, (j + 1) * 15, 9506318);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(wolf->mlx.init, wolf->mlx.win, \
		wolf->mlx.img2, 1400, 10);
}

void		menu(t_wolf *wolf)
{
	int c;

	c = (wolf->draw.texture == 1) ? 16777215 : 0;
	mlx_string_put(wolf->mlx.init, wolf->mlx.win, 10, 10, c,
		"move:              arrows or W, A, S, D");
	mlx_string_put(wolf->mlx.init, wolf->mlx.win, 10, 35, c,
		"run:               SHIFT");
	mlx_string_put(wolf->mlx.init, wolf->mlx.win, 10, 60, c,
		"texture:           SPACE");
	mlx_string_put(wolf->mlx.init, wolf->mlx.win, 10, 85, c,
		"texture + skybox:  0");
	mlx_string_put(wolf->mlx.init, wolf->mlx.win, 10, 110, c,
		"shadows ON/OFF:    5/6");
	mlx_string_put(wolf->mlx.init, wolf->mlx.win, 10, 135, c,
		"menu:              M");
	mlx_string_put(wolf->mlx.init, wolf->mlx.win, 10, 160, c,
		"reset:             ENTER");
	mlx_string_put(wolf->mlx.init, wolf->mlx.win, 10, 185, c,
		"exit:              (X) or ESC");
	where_i_am(wolf);
}
