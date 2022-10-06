/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:18 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:50:19 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_mlx *wind)
{
	double	x_step;
	double	y_step;
	int		move_pixels;

	move_pixels = 5;
	y_step = sin(wind->field_of_view * M_PI / 180) * move_pixels;
	x_step = cos(wind->field_of_view * M_PI / 180) * move_pixels;
	if (wind->map[(int)(wind->y_player + y_step * 2) / 20][(int)(wind->x_player + x_step * 2) / 20] == '0')
	{
		wind->x_player += x_step;
		wind->y_player += y_step;
	}
}
