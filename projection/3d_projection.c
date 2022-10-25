/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:49:51 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/23 16:39:50 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	projecting_rays(t_mlx *wind)
{
	int		x;
	double	angle;

	x = -1;
	angle = wind->field_of_view - HALF_WALL;
	wind->my_mlx.img = mlx_new_image(wind->mlx, WIN_WIDTH, WIN_HEIGHT);
	wind->my_mlx.addr = mlx_get_data_addr(wind->my_mlx.img, &wind->my_mlx.bpp, &wind->my_mlx.line_len, &wind->my_mlx.endian);
	while (++x < WIN_WIDTH)
	{
		cast_rays(wind, angle, x);
		angle += WALL_DIM / WIN_WIDTH;
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->my_mlx.img, 0, 0);
}

double	calculate_distance(double y_player, double x_player, double y_wall, double x_wall)
{
	return (sqrt(((x_player - x_wall) * (x_player - x_wall)) + ((y_player - y_wall) * (y_player - y_wall))));
}

void	cast_rays(t_mlx *wind, double angle, int x)
{
	double	px;
	double	py;
	char	direction;

	px = wind->x_player;
	py = wind->y_player;
	
	while (TRUE)
	{
		if (wind->map[(int)py / (int)WALL_DIM][(int)px / (int)WALL_DIM] == '1')
		{
			wind->x_endRay = px;
			wind->y_endRay = py;
			wind->distance = calculate_distance(wind->y_player, wind->x_player, wind->y_endRay, wind->x_endRay);
			direction = set_directions(wind->y_endRay, wind->x_endRay, wind);
			wind->dir_x = (int)round(wind->dir_x * (1000.0 / 64.0)) % 1000;
			break ;
		}
		px += cos((angle) * (M_PI / 180));
		py += sin((angle) * (M_PI / 180));
	}
	wind->corrected_distance = wind->distance * cos((angle - wind->field_of_view) * (M_PI / 180));
	casting_3d(wind->corrected_distance, x, wind, direction);
}



void	casting_3d(double distance, int height, t_mlx *mlx, char dir)
{
	int		width;
	double	floor_ceiling;
	double	projection_3d;
	char	*dst;
	double	distance_to_projection;
	width = 0;

	(void)dir;
	distance_to_projection = ((WIN_WIDTH / 2) / (tan((HALF_WALL) * (M_PI / 180))));

	projection_3d = (WALL_DIM / distance) * distance_to_projection;

	floor_ceiling = (WIN_HEIGHT / 2) - (projection_3d / 2);

						// ceilling 

	while (width < WIN_HEIGHT && width < floor_ceiling)
	{
		my_mlx_pixel_put(&mlx->my_mlx, height, width++, mlx->ceilling);
	}

						// Walls 

	int	save_wid = width;
	while (width < WIN_HEIGHT && width < floor_ceiling + projection_3d)
	{
		if (dir == 'N')
		{
			// 	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));

			dst = (mlx->my_mlx.addr_n + (((int)(round(((double)width - (double)save_wid + (projection_3d - (double)WIN_HEIGHT) * (projection_3d > WIN_HEIGHT) / 2) * (1000.0 / projection_3d))) % 1000) * mlx->my_mlx.line_len_n + (int)mlx->dir_x * (mlx->my_mlx.bpp_n / 8)));


			// my_mlx_pixel_put(&mlx->my_mlx, height, width++, BLACK);
			my_mlx_pixel_put(&mlx->my_mlx, height, width++, *(unsigned int *)dst);
		}
		else if (dir == 'S')
		{
			dst = (mlx->my_mlx.addr_s + (((int)(round(((double)width - (double)save_wid + (projection_3d - (double)WIN_HEIGHT) * (projection_3d > WIN_HEIGHT) / 2) * (1000.0 / projection_3d))) % 1000) * mlx->my_mlx.line_len_s + (int)mlx->dir_x * (mlx->my_mlx.bpp_s / 8)));
		// 	// color = *(int *)(mlx->my_mlx.addr_s + (((width - save_wid) % 1000) * mlx->my_mlx.line_len + (int)mlx->dir_x * (mlx->my_mlx.bpp / 8)));
		// 	// my_mlx_pixel_put(&mlx->my_mlx, height, width++, BLUE);
			my_mlx_pixel_put(&mlx->my_mlx, height, width++, *(unsigned int *)dst);
		}
		// else if (dir == 'W')
		// {
		// 	dst = (mlx->my_mlx.addr_w + (((int)(round(((double)width - (double)save_wid + (projection_3d - (double)WIN_HEIGHT) * (projection_3d > WIN_HEIGHT) / 2) * (1000.0 / projection_3d))) % 1000) * mlx->my_mlx.line_len_w + (int)mlx->dir_y * (mlx->my_mlx.bpp_w / 8)));
		// // 	// color = *(int *)(mlx->my_mlx.addr_w + (((width - save_wid) % 1000) * mlx->my_mlx.line_len + (int)mlx->dir_x * (mlx->my_mlx.bpp / 8)));
		// // 	// my_mlx_pixel_put(&mlx->my_mlx, height, width++, PURPLE);
		// 	my_mlx_pixel_put(&mlx->my_mlx, height, width++, *(unsigned int *)dst);
		// }
		else
		{
			// dst = (mlx->my_mlx.addr_e + (((int)(round(((double)width - (double)save_wid + (projection_3d - (double)WIN_HEIGHT) * (projection_3d > WIN_HEIGHT) / 2) * (1000.0 / projection_3d))) % 1000) * mlx->my_mlx.line_len_e + (int)mlx->dir_x * (mlx->my_mlx.bpp_e / 8)));
			// color = *(int *)(mlx->my_mlx.addr_e + (((width - save_wid) % 1000) * mlx->my_mlx.line_len + (int)mlx->dir_x * (mlx->my_mlx.bpp / 8)));
			my_mlx_pixel_put(&mlx->my_mlx, height, width++, WHITE);
			// my_mlx_pixel_put(&mlx->my_mlx, height, width++, *(unsigned int *)dst);
		}
	}

						// Floor 
	while (width < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&mlx->my_mlx, height, width++, mlx->floor);
	}
}

