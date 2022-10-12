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
	double x_step;
	double y_step;
	int		move_pixels;

	move_pixels = 5;
	//printf("Right\n");
	x_step = cos((wind->field_of_view / 2) * M_PI / 180) * move_pixels;
	y_step = sin((wind->field_of_view / 2) * M_PI / 180) * move_pixels;

	printf("wind->x_player => %f\n",wind->x_player);
	printf("x_step => %f\n",x_step);
	printf("wind->y_player => %f\n",wind->y_player);
	printf("y_step=> %f\n",y_step);

	if (wind->map[(int)(wind->y_player + y_step) / 64][(int)(wind->x_player + x_step) / 64] == '0')
	{
		wind->x_player += x_step;
		wind->y_player += y_step;
	}
}
