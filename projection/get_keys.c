/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:08 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/14 10:10:21 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_mlx *wind)
{
	wind->field_of_view -= 10.0;
	if (wind->field_of_view > 360.0)
		wind->field_of_view = 0;
	if (wind->field_of_view < 0)
		wind->field_of_view = 360.0;
}

void	rotate_right(t_mlx *wind)
{
	wind->field_of_view += 10.0;
	if (wind->field_of_view > 360.0)
		wind->field_of_view = 0;
	if (wind->field_of_view < 0)
		wind->field_of_view = 360.0;
}

int	get_keys(int press, t_mlx *wind)
{
	mlx_clear_window(wind->mlx, wind->window);
	if (press == 124)
		rotate_right(wind);
	if (press == 123)
		rotate_left(wind);
	if (press == 2)
		move_right(wind);
	if (press == 0)
		move_left(wind);
	if (press == 13)
		move_forward(wind);
	if (press == 1)
		move_backword(wind);
	if (press == 53)
		destroy_window(wind);
	projecting_rays(wind);
	return (0);
}
