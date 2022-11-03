/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:16:21 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/28 21:29:03 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	projecting_rays(t_mlx *wind)
{
	double	angle;

	wind->height = -1;
	angle = wind->field_of_view - HALF_WALL;
	wind->my_mlx.img = mlx_new_image(wind->mlx, WIN_W, WIN_H);
	wind->my_mlx.addr = mlx_get_data_addr(wind->my_mlx.img, &wind->my_mlx.bpp, &wind->my_mlx.line_len, &wind->my_mlx.endian);
	while (++wind->height < WIN_W)
	{
		cast_rays(wind, angle, wind->height);
		angle += WALL_DIM / WIN_W;
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->my_mlx.img, 0, 0);
}

void	draw(t_mlx *mlx, int i, char dir)
{
	if (dir == 'N')
		my_mlx_pixel_put(&mlx->my_mlx, mlx->height, mlx->width,
			*(unsigned int *)north_texture(mlx, i));
	else if (dir == 'S')
		my_mlx_pixel_put(&mlx->my_mlx, mlx->height, mlx->width,
			*(unsigned int *)south_texture(mlx, i));
	else if (dir == 'W')
		my_mlx_pixel_put(&mlx->my_mlx, mlx->height, mlx->width,
			*(unsigned int *)west_texture(mlx, i));
	else if (dir == 'E')
		my_mlx_pixel_put(&mlx->my_mlx, mlx->height, mlx->width,
			*(unsigned int *)east_texture(mlx, i));
}

void	cast_rays(t_mlx *wind, double angle, int x)
{
	double	px;
	double	py;

	wind->dir = '\0';
	px = wind->x_player;
	py = wind->y_player;
	wind->x_step = cos((angle) * (M_PI / 180));
	wind->y_step = sin((angle) * (M_PI / 180));
	while (TRUE)
	{
		wind->y_m = (int)(py / WALL_DIM);
		wind->x_m = (int)(px / WALL_DIM);
		if (wind->map[wind->y_m][wind->x_m] == '1' || wind->map[(int)(((py - wind->y_step) / 64))][wind->x_m] == '1' || wind->map[wind->y_m][(int)(((px - wind->x_step) / 64))] == '1')
		{
			wind->distance = calculate_distance(wind->y_player, wind->x_player, py, px);
			wind->dir = set_directions(py, px, wind);
			wind->where = (int)(wind->where * (1000.0 / 64.0)) % 1000;
			break ;
		}
		px += wind->x_step;
		py += wind->y_step;
	}
	casting_3d(fix_fisheye(wind, angle), x, wind, wind->dir);
}

void	casting_3d(double distance, int height, t_mlx *mlx, char dir)
{
	int	i;

	i = -1;
	mlx->width = 0;
	mlx->dst_to_projection = ((WIN_W / 2.0) / (tan((HALF_WALL) * (M_PI / 180))));
	mlx->projection_3d = (WALL_DIM / distance) * mlx->dst_to_projection;
	mlx->flo_cei = (WIN_H / 2) - (mlx->projection_3d / 2);
	while (mlx->width < WIN_H && mlx->width < mlx->flo_cei)
	{
		my_mlx_pixel_put(&mlx->my_mlx, height, mlx->width++, mlx->parsing->ceiling_color);
	}
	while (mlx->width < WIN_H && mlx->width < mlx->flo_cei + mlx->projection_3d && ++i < WIN_H)
	{
		draw(mlx, i, dir);
		mlx->width++;
	}
	while (mlx->width < WIN_H)
	{
		my_mlx_pixel_put(&mlx->my_mlx, height, mlx->width ++, mlx->parsing->floor_color);
	}
}
