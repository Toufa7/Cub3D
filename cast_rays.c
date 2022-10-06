/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:49:51 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/06 09:56:53 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	casting_3d(double distance, int i, t_mlx *mlx)
{
	int j = 0;

	distance = (20.0 / distance) * (960.0 / tan(30 * M_PI / 180));
	if (distance >= 1080)
		distance = 1080;
	if (distance == 0)
		distance = 1;
	int diff = (1080 - distance) / 2;
	while (j < 1080 && j < diff)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, i, j, GREEN);
		j++;	
	}
	while (j < 1080 && j < diff + distance)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, i, j, RED);
		j++;	
	}
	while (j < 1080)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, i, j, BLUE);
		j++;	
	}
}

void	cast_rays(t_mlx *wind, float nbr_ray , int i)
{
	double	px;
	double	py;
	int		p_x;
	int		p_y;
	int		dis_between_each_pix;
	double 	dist; 

	px = wind->x_player;
	py = wind->y_player;
	dis_between_each_pix = 2;
	while (TRUE)
	{
		p_x = (int)px / 20;
		p_y = (int)py / 20;
		if (wind->map[p_y][p_x] == '1')
		{
			wind->x_end_of_ray = p_x;
			wind->y_end_of_ray = p_y;
			dist = sqrt((wind->x_player - wind->x_end_of_ray * 20) * (wind->x_player - wind->x_end_of_ray * 20) + (wind->y_player - wind->y_end_of_ray * 20) * (wind->y_player - wind->y_end_of_ray * 20));
			break ;
		}
		px += cos((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		py += sin((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		mlx_pixel_put(wind->mlx, wind->window, px, py, GREEN);
	}
	// int j = 0;
	// while (++j < 1080)
	// {
	// 	mlx_pixel_put(wind->mlx, wind->window, i, j, 0);
	// }
	// casting_3d(dist,  i, wind);
}
