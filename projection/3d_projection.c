#include "../cub3d.h"

void	projecting_rays(t_mlx *wind)
{
	double	angle;

	wind->height = -1;
	angle = wind->field_of_view - HALF_WALL;
	wind->my_mlx.img = mlx_new_image(wind->mlx, WIN_W, WIN_H);
	wind->my_mlx.addr = mlx_get_data_addr(wind->my_mlx.img,
			&wind->my_mlx.bpp, &wind->my_mlx.line_len, &wind->my_mlx.endian);
	while (++wind->height < WIN_W)
	{
		cast_rays(wind, angle, wind->height);
		angle += WALL_DIM / WIN_W;
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->my_mlx.img, 0, 0);
}

double	calc_dist(double y_player, double x_player,
			double y_wall, double x_wall)
{
	return (sqrt(((x_player - x_wall) * (x_player - x_wall))
			+ ((y_player - y_wall) * (y_player - y_wall))));
}

void	draw(t_mlx *mlx, int i, char dir)
{
	if (dir == 'N')
	{
		my_mlx_pixel_put(&mlx->my_mlx, mlx->height, mlx->width,
			*(unsigned int *)north_texture(mlx, i));
	}
	else if (dir == 'S')
	{
		my_mlx_pixel_put(&mlx->my_mlx, mlx->height, mlx->width,
			*(unsigned int *)south_texture(mlx, i));
	}
	else if (dir == 'W')
	{
		my_mlx_pixel_put(&mlx->my_mlx, mlx->height, mlx->width,
			*(unsigned int *)west_texture(mlx, i));
	}
	else if (dir == 'E')
	{
		my_mlx_pixel_put(&mlx->my_mlx, mlx->height, mlx->width,
			*(unsigned int *)east_texture(mlx, i));
	}
}

void	cast_rays(t_mlx *wind, double angle, int x)
{
	double	px;
	double	py;
	char	direction;

	direction = '\0';
	px = wind->x_player;
	py = wind->y_player;
	while (TRUE)
	{
		if (wind->map[(int)py / (int)WALL_DIM][(int)px / (int)WALL_DIM] == '1')
		{
			wind->x_endray = px;
			wind->y_endray = py;
			wind->distance = calc_dist(wind->y_player, wind->x_player, py, px);
			direction = set_directions(wind->y_endray, wind->x_endray, wind);
			wind->where = (int)round(wind->where * (1000.0 / 64.0)) % 1000;
			break ;
		}
		px += cos((angle) * (M_PI / 180));
		py += sin((angle) * (M_PI / 180));
	}
	wind->corrected_distance = wind->distance
		* cos((angle - wind->field_of_view) * (M_PI / 180));
	casting_3d(wind->corrected_distance, x, wind, direction);
}

void	casting_3d(double distance, int height, t_mlx *mlx, char dir)
{
	int	i;

	i = -1;
	mlx->width = 0;
	mlx->dst_to_projection = ((WIN_W / 2) \
	/ (tan((HALF_WALL) * (M_PI / 180))));
	mlx->projection_3d = (WALL_DIM / distance) * mlx->dst_to_projection;
	mlx->flo_cei = (WIN_H / 2) - (mlx->projection_3d / 2);
	while (mlx->width < WIN_H && mlx->width < mlx->flo_cei)
		my_mlx_pixel_put(&mlx->my_mlx, height, mlx->width++, mlx->ceilling);
	while (mlx->width < WIN_H && mlx->width \
	< mlx->flo_cei + mlx->projection_3d && ++i < WIN_H)
	{
		draw(mlx, i, dir);
		mlx->width ++;
	}
	while (mlx->width < WIN_H)
		my_mlx_pixel_put(&mlx->my_mlx, height, mlx->width ++, mlx->floor);
}
