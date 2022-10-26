#include "../../cub3d.h"

void	move_forward(t_mlx *wind)
{
	double	y_step;
	double	x_step;
	int		y_map;
	int		x_map;

	y_step = sin(wind->field_of_view * M_PI / 180) * 5;
	x_step = cos(wind->field_of_view * M_PI / 180) * 5;
	y_map = (int)(wind->y_player + y_step) / WALL_DIM;
	x_map = (int)(wind->x_player + x_step) / WALL_DIM;
	if (wind->map[y_map][x_map] == '0')
	{
		wind->x_player += x_step;
		wind->y_player += y_step;
	}
}
