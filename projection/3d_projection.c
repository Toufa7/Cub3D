/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:49:51 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/20 10:56:13 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	set_direction(int y_player, int x_player, int py, int px, t_mlx *wind)
{
	double ppy = ((py / 64.0) + 1);
	double ppx = ((px / 64.0));

	double ppyy = ((py / 64.0) - 1);
	double ppxx = ((px / 64.0));

	if (y_player > py && x_player > px)
	{
		if ((int)(py + 1) % 64 == 0 && wind->map[(int)((py / 64) + 1)] && wind->map[(int)(ppy)][(int)(ppx)] == '0')
		{
			return ('N');
		}
		else
			return ('W');
	}
	else if (y_player > py && x_player < px)
	{
		if ((int)(py + 1) % 64 == 0 && wind->map[(int)((py / 64) + 1)] && wind->map[(int)(ppy)][(int)(ppx)] == '0')
		{
			return ('N');
		}
		else
			return ('E');
	}
	else if (y_player <= py && x_player <= px)
	{
		if ((int)(py) % 64 == 0 && wind->map[(int)((py / 64) - 1)] && wind->map[(int)(ppyy)][(int)(ppxx)] == '0')
			return ('S');
		else
			return ('E');
	}
	else if (y_player <= py && x_player >= px)
	{
		if ((int)(py) % 64 == 0 && wind->map[(int)((py / 64) - 1)] && wind->map[(int)(ppyy)][(int)(ppxx)] == '0')
			return ('S');
		else
			return ('W');
	}
	return (0);

	// if (y_player >= ((py)) && x_player >= ((px)))
	// {
	// 	if ((int)(py + 1 ) % (int)64 == 0)
	// 		return ('N');
	// 	else
	// 		return ('W');
	// }
	// else if (y_player > ((py)) && x_player < ((px)))
	// {
	// 	if ((int)(py + 1 ) % (int)WALL_DIM == 0)
	// 		return ('N');
	// 	else
	// 		return ('E');
	// }
	// else if (y_player <= ((py)) && x_player <= ((px)))
	// {
	// 	if ((int)(py) % (int)WALL_DIM == 0)
	// 		return ('S');
	// 	else
	// 		return ('E');
	// }
	// else if (y_player < ((py)) && x_player > ((px)))
	// {
	// 	if ((int)(py) % (int)WALL_DIM == 0)
	// 		return ('S');
	// 	else
	// 		return ('W');
	// }
	return (0);
}

void	projecting_rays(t_mlx *wind)
{
	int		x;
	float	angle;

	x = -1;
	angle = wind->field_of_view - 32;
	wind->my_mlx.img = mlx_new_image(wind->mlx, WIN_WIDTH, WIN_HEIGHT);
	wind->my_mlx.addr = mlx_get_data_addr(wind->my_mlx.img, &wind->my_mlx.bpp,
			&wind->my_mlx.line_len, &wind->my_mlx.endian);
	while (++x < WIN_WIDTH)
	{
		cast_rays(wind, angle, x);
		angle += WALL_DIM / 1910;
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->my_mlx.img, 0, 0);
}

void	casting_3d(float distance, int height, t_mlx *mlx, char dir)
{
	int		width;
	float	floor_ceiling;
	float	projection_3d;
	float	distance_to_projection;

	width = 0;
	distance_to_projection = ((WIN_WIDTH / 2) / (tan((WALL_DIM / 2) * (M_PI / 180))));
	projection_3d = (WALL_DIM / distance) * distance_to_projection;
	floor_ceiling = (WIN_HEIGHT / 2) - (projection_3d / 2);
	while (width < WIN_HEIGHT && width < floor_ceiling)
		my_mlx_pixel_put(&mlx->my_mlx, height, width++, mlx->parsing.color_c);
	while (width < WIN_HEIGHT && width < floor_ceiling + projection_3d)
	{
		if (dir == 'W')
			my_mlx_pixel_put(&mlx->my_mlx, height, width++, WHITE);
		else if (dir == 'E')
			my_mlx_pixel_put(&mlx->my_mlx, height, width++, PURPLE);
		else if (dir == 'N')
			my_mlx_pixel_put(&mlx->my_mlx, height, width++, BLUE);
		else if (dir == 'S')
			my_mlx_pixel_put(&mlx->my_mlx, height, width++, BLACK);
	}
	while (width < WIN_HEIGHT)
		my_mlx_pixel_put(&mlx->my_mlx, height, width++, mlx->parsing.color_f);
}

float	calculate_distance(float y_player, float x_player,
		float y_wall, float x_wall)
{
	return (sqrt(((x_player - x_wall) * (x_player - x_wall))
			+ ((y_player - y_wall) * (y_player - y_wall))));
}

void	cast_rays(t_mlx *wind, float angle, int x)
{
	float	px;
	float	py;
	float	distance;
	float	corrected_distance;
	char	direction;

	px = wind->x_player;
	py = wind->y_player;
	while (TRUE)
	{
		if (wind->map[(int)py / (int)WALL_DIM][(int)px / (int)WALL_DIM] == '1')
		{
			wind->x_end_of_ray = px;
			wind->y_end_of_ray = py;
			direction = set_direction((int)wind->y_player, (int)wind->x_player, (int)wind->y_end_of_ray, (int)wind->x_end_of_ray, wind);
			distance = calculate_distance(wind->y_player, wind->x_player,
					wind->y_end_of_ray, wind->x_end_of_ray);
			break ;
		}
		px += cos((angle) * (M_PI / 180));
		py += sin((angle) * (M_PI / 180));
	}
	corrected_distance = distance
		* cos((angle - wind->field_of_view) * (M_PI / 180));
	casting_3d(corrected_distance, x, wind, direction);
}
