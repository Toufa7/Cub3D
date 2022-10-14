/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:45 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:50:46 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_right(t_mlx *wind)
{
	int		y_map;
	int		x_map;
	double	y_step;
	double	x_step;

	x_step = cos((wind->field_of_view / 2) * M_PI / 180) * 5;
	y_step = sin((wind->field_of_view / 2) * M_PI / 180) * 5;
	y_map = (int)(wind->y_player + y_step) / 64;
	x_map = (int)(wind->x_player + x_step) / 64;
	if (wind->map[y_map][x_map] == '0')
	{
		wind->x_player += x_step;
		wind->y_player += y_step;
	}
}
