/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:26:17 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/28 21:26:19 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_left(t_mlx *wind)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;

	x_step = cos((wind->field_of_view + 90) * (M_PI / 180)) * PX_MOVE;
	y_step = sin((wind->field_of_view + 90) * (M_PI / 180)) * PX_MOVE;
	y_map = (int)(wind->y_player - y_step) / WALL_DIM;
	x_map = (int)(wind->x_player - x_step) / WALL_DIM;
	if (wind->map[y_map][x_map] == '0')
	{
		wind->x_player -= x_step;
		wind->y_player -= y_step;
	}
}
