/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:08:18 by tbahlai           #+#    #+#             */
/*   Updated: 2019/03/08 18:08:19 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		write_texture(t_wolf *wolf)
{
	wolf->text[0].data = (int*)mlx_get_data_addr(wolf->text[0].img, \
		&wolf->text[0].bpp, &wolf->text[0].sl, &wolf->text[0].endian);
	wolf->text[1].data = (int*)mlx_get_data_addr(wolf->text[1].img, \
		&wolf->text[1].bpp, &wolf->text[1].sl, &wolf->text[1].endian);
	wolf->text[2].data = (int*)mlx_get_data_addr(wolf->text[2].img, \
		&wolf->text[2].bpp, &wolf->text[2].sl, &wolf->text[2].endian);
	wolf->text[3].data = (int*)mlx_get_data_addr(wolf->text[3].img, \
		&wolf->text[3].bpp, &wolf->text[3].sl, &wolf->text[3].endian);
	wolf->text[4].data = (int*)mlx_get_data_addr(wolf->text[4].img, \
		&wolf->text[4].bpp, &wolf->text[4].sl, &wolf->text[4].endian);
	wolf->text[5].data = (int*)mlx_get_data_addr(wolf->text[5].img, \
		&wolf->text[5].bpp, &wolf->text[5].sl, &wolf->text[5].endian);
	wolf->text_sky[0].data = (int*)mlx_get_data_addr(wolf->text_sky[0].img, \
		&wolf->text_sky[0].bpp, &wolf->text_sky[0].sl, \
		&wolf->text_sky[0].endian);
	wolf->text[7].data = (int*)mlx_get_data_addr(wolf->text[7].img, \
		&wolf->text[7].bpp, &wolf->text[7].sl, &wolf->text[7].endian);
	wolf->text[6].data = (int*)mlx_get_data_addr(wolf->text[6].img, \
		&wolf->text[6].bpp, &wolf->text[6].sl, &wolf->text[6].endian);
}

void		initial_texture(t_wolf *wolf)
{
	int	a;
	int	m;

	m = 512;
	a = 64;
	if ((!(wolf->text[0].img = mlx_xpm_file_to_image(wolf->mlx.init, \
		"pics/colorstone.xpm", &a, &a))) ||
		(!(wolf->text[1].img = mlx_xpm_file_to_image(wolf->mlx.init, \
			"pics/mossy.xpm", &a, &a))) ||
		(!(wolf->text[2].img = mlx_xpm_file_to_image(wolf->mlx.init, \
			"pics/redbrick.xpm", &a, &a))) ||
		(!(wolf->text[3].img = mlx_xpm_file_to_image(wolf->mlx.init, \
			"pics/eagle.xpm", &a, &a))) ||
		(!(wolf->text[4].img = mlx_xpm_file_to_image(wolf->mlx.init, \
			"pics/bluestone.xpm", &a, &a))) ||
		(!(wolf->text[5].img = mlx_xpm_file_to_image(wolf->mlx.init, \
			"pics/wood.xpm", &a, &a))) ||
		(!(wolf->text[7].img = mlx_xpm_file_to_image(wolf->mlx.init, \
			"pics/beach.xpm", &m, &m))) ||
		(!(wolf->text[6].img = mlx_xpm_file_to_image(wolf->mlx.init, \
			"pics/purplestone.xpm", &a, &a))) ||
		(!(wolf->text_sky[0].img = mlx_xpm_file_to_image(wolf->mlx.init, \
			"pics/sky111.xpm", &m, &m))))
		error(6);
	write_texture(wolf);
}
