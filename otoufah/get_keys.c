/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:08 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:50:09 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_ray_left(t_mlx *wind)
{
	//printf("Moving Left\n");
	//printf("FOV [%f]\n",wind->field_of_view);
	wind->field_of_view -=10;
	if (wind->field_of_view > 360)
		wind->field_of_view = 0;
	if (wind->field_of_view < 0)
		wind->field_of_view = 360;
}

void	move_ray_right(t_mlx *wind)
{
	//printf("Moving Right\n");
	//printf("FOV [%f]\n",wind->field_of_view);
	wind->field_of_view +=10;
	if (wind->field_of_view > 360)
		wind->field_of_view = 0;
	if (wind->field_of_view < 0)
		wind->field_of_view = 360;
}


int	get_keys(int press, t_mlx *wind)
{
	mlx_clear_window(wind->mlx, wind->window);
	if (press == 125)
		move_backword(wind);
	if (press == 126)
		move_forward(wind);
	if (press == 0)
		move_ray_left(wind);
	if (press == 2)
		move_ray_right(wind);

	if (press == 124)
		move_left(wind);
	if (press == 123) 
		move_right(wind);
	if (press == 53)
        destroy_window(wind);
	map_filling(wind);
	return (0);
}