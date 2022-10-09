/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:49:51 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/09 15:44:34 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	casting_3d(double distance, int i, t_mlx *mlx)
{
	int j = 0;
	int diff;
	double distance_to_projection_plan;
	printf("Distace_1 -> %f\n", distance);

	distance_to_projection_plan = 64.0 / distance;

	distance = distance_to_projection_plan * (1080 / 2);

	printf("Distace_2 -> %f\n", distance);

	diff = (1080 - distance) / 2;

	printf("Diff -> %d\n", diff);
	// exit(0);
	// exit(0);
	while (j < 1080 && j < diff)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, i, j, BLUE);
		j++;	
	}
	while (j < 1080 && j < diff + distance)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, i, j, RED);
		j++;	
	}
	while (j < 1080)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, i, j, GREEN);
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
		p_x = (int)px / 64;
		p_y = (int)py / 64;
		if (wind->map[p_y][p_x] == '1')
		{
			wind->x_end_of_ray = p_x;
			wind->y_end_of_ray = p_y;
			dist = sqrt((wind->x_player - wind->x_end_of_ray * 64) * (wind->x_player - wind->x_end_of_ray * 64) + (wind->y_player - wind->y_end_of_ray * 64) * (wind->y_player - wind->y_end_of_ray * 64));
			break ;
		}
		px += cos((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		py += sin((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		// mlx_pixel_put(wind->mlx, wind->window, px, py, GREEN);
	}
	casting_3d(dist,  i, wind);
}
