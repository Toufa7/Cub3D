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

#include "cub3d.h"

void	cast_rays(t_mlx *wind, float nbr_ray)
{
	double	px;
	double	py;
	int		distance_ray;
	int		p_x;
	int		p_y;
	int		dis_between_each_pix;

	px = wind->x_player;
	py = wind->y_player;
	dis_between_each_pix = 2;
	distance_ray = 0;
	while (distance_ray < 60 * (38 - 2 / 2))
	{
		// Getting Player postion in the Map dividing
		p_x = (int)px / 60;
		p_y = (int)py / 60;
		if (wind->map[p_y][p_x] == '1')
		{
			wind->x_end_of_ray = p_x;
			wind->y_end_of_ray = p_y;
			// printf("Rays End at : -> [%d py][%d px]\n", wind->y_end_of_ray * 60, wind->x_end_of_ray * 60);
			break ;
		}
		px += cos((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		py += sin((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		mlx_pixel_put(wind->mlx, wind->window, px, py, GREEN);
		distance_ray++;
	}
}
