/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:49:51 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/09 10:56:55 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	power(int nb, int power)
{
	int	i;
	int	once;

	i = 0;
	once = 1;
	if (power < 0)
		return (0);
	while (i++ < power)
		once = once * nb;
	return (once);
}


void	casting_3d(double distance, int i, t_mlx *mlx)
{
	int		j;
	int		up_down;
	int		ceiling;
	double	projection_3d;

	printf("Distance %f\n", distance);
	projection_3d = (64.0 / distance) * (1080 / 2);
	printf("projection_3d %f\n", projection_3d);
	printf("ceiling %d\n", ceiling);
	exit(0);
	up_down = projection_3d / 2;
	ceiling = (1080 / 2) - up_down;
	j = 0;
	while (j < 1080 && j < ceiling) 
	{
		my_mlx_pixel_put(&mlx->data, i, j, BLUE);
		j++;	
	}
	// while (j < 1080 &&  j < ceiling + projection_3d)
	// {
	// 	my_mlx_pixel_put(&mlx->data, i, j, RED);
	// 	j++;	
	// }
	// while (j < 1080)
	// {
	// 	my_mlx_pixel_put(&mlx->data, i, j, GREEN);
	// 	j++;	
	// }
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->data.img, 0, 0);

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
			printf("I Enter\n");
			wind->x_end_of_ray = p_x;
			wind->y_end_of_ray = p_y;
			dist = sqrt(power((wind->x_player - wind->x_end_of_ray * 64), 2) + power((wind->y_player - wind->y_end_of_ray * 64), 2));
			break ;
		}
		px += cos((nbr_ray) * M_PI / 180) * 2;
		py += sin((nbr_ray) * M_PI / 180) * 2;
	}
	casting_3d(dist,  i, wind);
}
