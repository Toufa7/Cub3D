/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:42:44 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/22 22:51:33 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

char	set_directions(double y_player, double x_player, double py, double px, t_mlx *wind)
{
	if (y_player > py && x_player > px)
	{
		if ((int)(py + 1) % 64 == 0 && wind->map[(int)(py / 64.0) + 1][(int)(px / 64.0)] == '0')
			return ('N');
		else
			return ('W');
	}
	else if (y_player > py && x_player < px)
	{
		if ((int)(py + 1) % 64 == 0 && wind->map[(int)((py / 64.0) + 1)][(int)(px / 64.0)] == '0')
			return ('N');
		else
			return ('E');
	}
	else if (y_player <= py && x_player <= px)
	{
		if ((int)(py) % 64 == 0 && wind->map[(int)((py / 64.0) - 1)][(int)(px / 64.0)] == '0')
			return ('S');
		else
			return ('E');
	}
	else if (y_player <= py && x_player >= px)
	{
		if ((int)(py) % 64 == 0 && wind->map[(int)((py / 64.0) - 1)][(int)(px / 64.0)] == '0')
			return ('S');
		else
			return ('W');
	}
	return (0);
}
