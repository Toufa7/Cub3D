/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_backword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:27 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:50:28 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_backword(t_mlx *wind)
{
	double	x_step;
	double	y_step;
	int		move_pixels;

	move_pixels = 5;
	y_step = sin(wind->field_of_view * M_PI / 180) * move_pixels;
	x_step = cos(wind->field_of_view * M_PI / 180) * move_pixels;
	// printf("Back Player X Position => %f\n", x_step);
	// printf("Back Player Y Position => %f\n", y_step);
	if (wind->map[(int)(wind->y_player - y_step * 2) / 60][(int)(wind->x_player - x_step * 2) / 60] == '0')
	{
		wind->x_player -= x_step;
		wind->y_player -= y_step;
	}
}
