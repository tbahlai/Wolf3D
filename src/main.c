/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:20:07 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/25 14:20:09 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		wolf_init(t_wolf *wolf)
{
	wolf->draw.dir_x = -1;
	wolf->draw.dir_y = 0;
	wolf->draw.plane_x = 0;
	wolf->draw.plane_y = 0.66;
	wolf->draw.time = 0;
	wolf->draw.old_time = 0;
	wolf->draw.color = 235689;
	wolf->draw.rs = 0.03;
	wolf->draw.ms = 0.05;
	wolf->move.right = 0;
	wolf->move.left = 0;
	wolf->move.back = 0;
	wolf->draw.texture = 0;
	wolf->move.forward = 0;
	wolf->draw.sky = 0;
	wolf->draw.skybox = 0;
	wolf->draw.shadow = 0;
	wolf->draw.menu = 1;
	initial_texture(wolf);
	system("afplay ./pics/sound.mp3&");
}

void		init_wind(t_wolf *wolf)
{
	char	*title;

	title = ft_strjoin("Wolf3D: ", wolf->map.name_map);
	wolf->mlx.init = mlx_init();
	wolf->mlx.win = mlx_new_window(wolf->mlx.init, WID, HEIG, title);
	free(title);
}

int			destroy(void)
{
	system("killall afplay");
	exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	t_wolf	*wolf;

	if (!(wolf = (t_wolf *)malloc(sizeof(t_wolf))))
		return (0);
	if (ac != 2)
		error(8);
	wolf->map.name_map = ft_strdup(av[1]);
	if (!(valid_file(wolf, av)))
		return (0);
	init_wind(wolf);
	wolf->mlx.img = mlx_new_image(wolf->mlx.init, WID, HEIG);
	wolf->mlx.img_ptr = (int *)mlx_get_data_addr(wolf->mlx.img, \
		&wolf->mlx.bpp, &wolf->mlx.sl, &wolf->mlx.endian);
	wolf->mlx.img2 = mlx_new_image(wolf->mlx.init, WID, HEIG);
	wolf->mlx.data2 = (int *)mlx_get_data_addr(wolf->mlx.img2,
		&wolf->mlx.bpp2, &wolf->mlx.sl2, &wolf->mlx.endian2);
	wolf_init(wolf);
	raycasting(wolf);
	mlx_hook(wolf->mlx.win, 2, 0, keyss_hook, wolf);
	mlx_hook(wolf->mlx.win, 3, 0, key_reset, wolf);
	mlx_hook(wolf->mlx.win, 17, 0, destroy, wolf);
	mlx_loop_hook(wolf->mlx.init, move, wolf);
	mlx_loop(wolf->mlx.init);
	return (0);
}
