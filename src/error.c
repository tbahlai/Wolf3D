/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:33:00 by tbahlai           #+#    #+#             */
/*   Updated: 2019/03/09 16:33:00 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		error(int flag)
{
	if (flag == 1)
		ft_putstr("This is a directory");
	else if (flag == 2)
		ft_putstr("Give me valid file");
	else if (flag == 3)
		ft_putstr("Not valid a map");
	else if (flag == 4)
		ft_putstr("TOO BIG MAP");
	else if (flag == 5)
		ft_putstr("Invalid map");
	else if (flag == 6)
		ft_putstr("No texture");
	else if (flag == 7)
		system("killall afplay");
	else if (flag == 8)
		ft_putstr("Example: ./wolf3d <map>");
	else if (flag == 9)
		ft_putstr("Error number");
	exit(0);
}
