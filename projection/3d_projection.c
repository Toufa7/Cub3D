/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:49:51 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/14 10:51:38 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	projecting_rays(t_mlx *wind)
{
	int		i;
	double	fov;

	i = -1;
	fov = wind->field_of_view - 32;
	wind->my_mlx.img = mlx_new_image(wind->mlx, 1920, 1080);
	wind->my_mlx.addr = mlx_get_data_addr(wind->my_mlx.img, &wind->my_mlx.bits_per_pixel, &wind->my_mlx.line_length, &wind->my_mlx.endian);
	while (++i < 1920)
	{
		cast_rays(wind, fov, i);
		fov += 64.0/1920;
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->my_mlx.img, 0, 0);
}

void	casting_3d(double distance, int i, t_mlx *mlx)
{
	int	j;
	double	floor_ceiling;
	double	projection_3d;
	double	distance_to_projection;

	j = 0;
	distance_to_projection = ((1920 / 2) / (tan(32.0 * (M_PI / 180))));
	projection_3d = (64.0 / distance) * distance_to_projection;
	floor_ceiling = (1080 / 2) - (projection_3d / 2);
	while (j < 1080 && j < floor_ceiling)
		my_mlx_pixel_put(&mlx->my_mlx, i, j++, BLUE);
	while (j < 1080 && j < floor_ceiling + projection_3d)
		my_mlx_pixel_put(&mlx->my_mlx, i, j++, RED);
	while (j < 1080)
		my_mlx_pixel_put(&mlx->my_mlx, i, j++, GREEN);
}

double	calculate_distance(double y_player, double x_player,double y_wall, double x_wall)
{
	return (sqrt(((x_player - x_wall) * (x_player - x_wall)) + ((y_player - y_wall) * (y_player - y_wall))));
}

void	cast_rays(t_mlx *wind, double fov , int i)
{
	double	px;
	double	py;
	double 	distance;

	px = wind->x_player;
	py = wind->y_player;
	while (TRUE)
	{
		if (wind->map[(int)py / 64][(int)px / 64] == '1')
		{
			wind->x_end_of_ray = px;
			wind->y_end_of_ray = py;
			distance = calculate_distance(wind->y_player, wind->x_player,wind->y_end_of_ray, wind->x_end_of_ray);
			break ;
		}
		px += cos((fov) * (M_PI / 180));
		py += sin((fov) * (M_PI / 180));
	}
	casting_3d(distance,  i, wind);
}

