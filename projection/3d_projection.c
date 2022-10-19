/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:49:51 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/17 20:15:43 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	projecting_rays(t_mlx *wind)
{
	int		x;
	double	angle;

	x = -1;
	angle = wind->field_of_view - 32;
	wind->my_mlx.img = mlx_new_image(wind->mlx, 1920, 1080);
	wind->my_mlx.addr = mlx_get_data_addr(wind->my_mlx.img, &wind->my_mlx.bpp,
			&wind->my_mlx.line_len, &wind->my_mlx.endian);
	while (++x < 1920)
	{
		cast_rays(wind, angle, x);
		angle += 64.0 / 1920;
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->my_mlx.img, 0, 0);
}

void	casting_3d(double distance, int height, t_mlx *mlx)
{
	int		width;
	double	floor_ceiling;
	double	projection_3d;
	double	distance_to_projection;

	width = 0;
	distance_to_projection = ((1920 / 2) / (tan((32.0) * (M_PI / 180))));
	projection_3d = (64.0 / distance) * distance_to_projection;
	floor_ceiling = (1080 / 2) - (projection_3d / 2);
	while (width < 1080 && width < floor_ceiling)
		my_mlx_pixel_put(&mlx->my_mlx, height, width++, BLUE);
	while (width < 1080 && width < floor_ceiling + projection_3d)
		my_mlx_pixel_put(&mlx->my_mlx, height, width++, RED);
	while (width < 1080)
		my_mlx_pixel_put(&mlx->my_mlx, height, width++, GREEN);
}

double	calculate_distance(double y_player, double x_player,
		double y_wall, double x_wall)
{
	return (sqrt(((x_player - x_wall) * (x_player - x_wall))
			+ ((y_player - y_wall) * (y_player - y_wall))));
}

void	cast_rays(t_mlx *wind, double angle, int x)
{
	double	px;
	double	py;
	double	distance;
	double	corrected_distance;

	px = wind->x_player;
	py = wind->y_player;
	while (TRUE)
	{
		if (wind->map[(int)py / 64][(int)px / 64] == '1'
			|| wind->map[(int)(py - 1) / 64][(int)(px - 1) / 64] == '1'
			|| wind->map[(int)(py + 1) / 64][(int)(px + 1) / 64] == '1' )
		{
			wind->x_end_of_ray = px;
			wind->y_end_of_ray = py;
			distance = calculate_distance(wind->y_player, wind->x_player,
					wind->y_end_of_ray, wind->x_end_of_ray);
			break ;
		}
		px += cos((angle) * (M_PI / 180));
		py += sin((angle) * (M_PI / 180));
	}
	corrected_distance = distance
		* cos((angle - wind->field_of_view) * (M_PI / 180));
	casting_3d(corrected_distance, x, wind);
}