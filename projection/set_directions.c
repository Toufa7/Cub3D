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

char	set_directions(double w_y, double w_x, t_mlx *wind)
{
	if (wind->y_player > w_y && wind->x_player > w_x)
	{
		if ((int)(w_y + 1) % 64 == 0
			&& wind->map[(int)(w_y / 64.0) + 1][(int)(w_x / 64.0)] == '0')
			return ('N');
		else
			return ('W');
	}
	else if (wind->y_player > w_y && wind->x_player < w_x)
	{
		if ((int)(w_y + 1) % 64 == 0
			&& wind->map[(int)((w_y / 64.0) + 1)][(int)(w_x / 64.0)] == '0')
			return ('N');
		else
			return ('E');
	}
	else if (wind->y_player <= w_y && wind->x_player <= w_x)
	{
		if ((int)(w_y) % 64 == 0
			&& wind->map[(int)((w_y / 64.0) - 1)][(int)(w_x / 64.0)] == '0')
			return ('S');
		else
			return ('E');
	}
	else if (wind->y_player <= w_y && wind->x_player >= w_x)
	{
		if ((int)(w_y) % 64 == 0
			&& wind->map[(int)((w_y / 64.0) - 1)][(int)(w_x / 64.0)] == '0')
			return ('S');
		else
			return ('W');
	}
	return (0);
}
