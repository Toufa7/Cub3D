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
	double	player_view;

	wind->my_mlx.img = mlx_new_image(wind->mlx, 1920, 1080);
	wind->my_mlx.addr = mlx_get_data_addr(wind->my_mlx.img, &wind->my_mlx.bits_per_pixel, &wind->my_mlx.line_length, &wind->my_mlx.endian);

	i = -1;
	nbr_of_rays = 1920;
	player_view = wind->field_of_view - 32;
	while (++i < nbr_of_rays)
	{
		cast_rays(wind, player_view, i);
		player_view += 0.02;
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->my_mlx.img, 0, 0);
}

void	casting_3d(double distance, int i, t_mlx *mlx)
{
	int		j;
	int		up_down;
	int		ceiling;
	double	projection_3d;

	projection_3d = (64.0 / distance) * (1080 / 2);
	
	up_down = projection_3d / 2;

	ceiling = (1080 / 2) - up_down;

	j = 0;
	while (j < 1080 && j < ceiling)
	{
		// mlx_pixel_put(mlx->mlx, mlx->window, i, j, BLUE);
		my_mlx_pixel_put(&mlx->my_mlx, i, j, BLUE);
		j++;	
	}

	while (j < 1080 && j < ceiling + projection_3d)
	{
		// mlx_pixel_put(mlx->mlx, mlx->window, i, j, RED);
		my_mlx_pixel_put(&mlx->my_mlx, i, j, RED);
		j++;	
	}
	while (j < 1080)
	{
		// mlx_pixel_put(mlx->mlx, mlx->window, i, j, GREEN);
		my_mlx_pixel_put(&mlx->my_mlx, i, j, GREEN);
		j++;	
	}
}

void	cast_rays(t_mlx *wind, float nbr_ray , int i)
{
	double	px;
	double	py;
	int		p_x;
	int		p_y;
	double 	dist;


	px = wind->x_player;
	py = wind->y_player;
	while (TRUE)
	{
		p_x = (int)px / 64;
		p_y = (int)py / 64;
		if (wind->map[p_y][p_x] == '1')
		{
			wind->x_end_of_ray = p_x;
			wind->y_end_of_ray = p_y;
			dist = sqrt(((wind->x_player - wind->x_end_of_ray * 64) * (wind->x_player - wind->x_end_of_ray * 64)) + ((wind->y_player - wind->y_end_of_ray * 64) * (wind->y_player - wind->y_end_of_ray * 64)));
			break ;
		}
		px += cos((nbr_ray) * M_PI / 180) * 2;
		py += sin((nbr_ray) * M_PI / 180) * 2;
	}
	casting_3d(dist,  i, wind);
}
