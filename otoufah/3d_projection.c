/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:49:51 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:49:52 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	projecting_rays(t_mlx *wind)
{
	int		i;
	int		nbr_of_rays;
	float	player_view;

	wind->my_mlx.img = mlx_new_image(wind->mlx, 1920, 1080);
	wind->my_mlx.addr = mlx_get_data_addr(wind->my_mlx.img, &wind->my_mlx.bits_per_pixel, &wind->my_mlx.line_length, &wind->my_mlx.endian);

	i = -1;
	nbr_of_rays = 1920;
	player_view = wind->field_of_view - 32;
	while (++i < nbr_of_rays)
	{
		cast_rays(wind, player_view, i);
		player_view += 0.03333333333;
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->my_mlx.img, 0, 0);
}

void	casting_3d(float distance, int i, t_mlx *mlx)
{
	int		j;
	int		up_down;
	float	projection_3d;

	projection_3d = (64.0 / distance) * (1080 / 2);
	up_down = (1080 / 2) - (projection_3d / 2);

	j = 0;
	while (j < 1080 && j < up_down)
	{
		my_mlx_pixel_put(&mlx->my_mlx, i, j, BLUE);
		j++;	
	}
	while (j < 1080 && j < up_down + projection_3d)
	{
		my_mlx_pixel_put(&mlx->my_mlx, i, j, RED);
		j++;	
	}
	while (j < 1080)
	{
		my_mlx_pixel_put(&mlx->my_mlx, i, j, GREEN);
		j++;	
	}
}

void	cast_rays(t_mlx *wind, float fov , int i)
{
	float	px;
	float	py;
	float 	distance;
	int		y = 0;

	px = wind->x_player;
	py = wind->y_player;
	while (TRUE)
	{
		if (wind->map[(int)py / 64][(int)px / 64] == '1')
		{
			wind->x_end_of_ray = px;
			wind->y_end_of_ray = py;
			distance = sqrt(((wind->x_player - wind->x_end_of_ray) * (wind->x_player - wind->x_end_of_ray)) + ((wind->y_player - wind->y_end_of_ray) * (wind->y_player - wind->y_end_of_ray)));

			break ;
		}
		px += cos((fov) * M_PI / 180);
		py += sin((fov) * M_PI / 180);
		y++;
	}
	casting_3d(distance,  i, wind);
}

