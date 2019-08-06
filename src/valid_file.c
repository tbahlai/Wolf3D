/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:20:53 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/25 14:20:54 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		check_border(t_wolf *wolf)
{
	int i;
	int j;

	i = 0;
	while (i < wolf->map.width)
	{
		j = 0;
		while (j < wolf->map.height)
		{
			if (wolf->map.value[0][i] == 0 || wolf->map.value[j][0] == 0 || \
				wolf->map.value[j][wolf->map.width - 1] == 0 || \
				wolf->map.value[wolf->map.height - 1][i] == 0)
				error(5);
			if (wolf->map.value[j][i] == 0)
			{
				wolf->draw.pos_x = j + 0.65;
				wolf->draw.pos_y = i + 0.8;
				return ;
			}
			j++;
		}
		i++;
	}
	error(5);
}

void		fill_the_map(t_wolf *wolf, char **map)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	wolf->map.value = (int **)malloc(sizeof(int*) * wolf->map.height);
	while (i < wolf->map.height)
	{
		j = 0;
		wolf->map.value[i] = (int *)malloc(sizeof(int) * wolf->map.width);
		tmp = ft_strsplit(map[i], ' ');
		free(map[i]);
		while (j < wolf->map.width)
		{
			wolf->map.value[i][j] = atoi(tmp[j]);
			free(tmp[j]);
			if (wolf->map.value[i][j] > 9)
				error(9);
			j++;
		}
		free(tmp);
		i++;
	}
}

int			check_map(t_wolf *wolf, char *buff)
{
	int i;
	int len;

	i = 0;
	len = 0;
	wolf->map.width = ft_len_line(buff);
	wolf->map.height = ft_count_line(buff);
	if (wolf->map.width > 50 || wolf->map.height > 50)
		error(4);
	while (buff[i])
	{
		if (buff[i] != ' ' && buff[i] != '\n' && (!(ft_isdigit(buff[i]))))
			return (0);
		len++;
		if (buff[i] == '\n')
		{
			if ((len - 1) != wolf->map.width)
				return (0);
			len = 0;
		}
		i++;
	}
	return (1);
}

int			valid_file(t_wolf *wolf, char **av)
{
	int		fd;
	int		dir;
	char	*buff;
	int		i;
	char	**map;

	i = 0;
	if ((dir = open(av[1], O_DIRECTORY)) > 0)
		error(1);
	buff = ft_strnew(B_SIZE);
	if ((!(fd = open(av[1], O_RDONLY))) || (read(fd, buff, B_SIZE)) < 1)
		error(2);
	if (!(check_map(wolf, buff)))
		error(3);
	while (buff[i] && buff[i] != '\n')
	{
		if (buff[i] == ' ')
			wolf->map.width--;
		i++;
	}
	map = ft_strsplit(buff, '\n');
	fill_the_map(wolf, map);
	FREE(buff, map);
	check_border(wolf);
	return (fd);
}
