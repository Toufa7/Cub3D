#include "../cub3d.h"

char	set_directions(double w_y, double w_x, t_mlx *wind)
{
	if (wind->y_player > w_y && wind->x_player > w_x)
	{
		if ((int)(w_y + 1) % 64 == 0 && wind->map[(int)(w_y / 64.0) + 1][(int)(w_x / 64.0)] == '0')
		{
			wind->where= w_x;
			return ('N');
		}
		else
		{
			wind->where= w_y;
			return ('W');
		}
	}
	else if (wind->y_player > w_y && wind->x_player < w_x)
	{
		if ((int)(w_y + 1) % 64 == 0 && wind->map[(int)((w_y / 64.0) + 1)][(int)(w_x / 64.0)] == '0')
		{
			wind->where= w_x;
			return ('N');
		}
		else
		{
			wind->where= w_y;
			return ('E');
		}
	}
	else if (wind->y_player <= w_y && wind->x_player <= w_x)
	{
		if ((int)(w_y) % 64 == 0 && wind->map[(int)((w_y / 64.0) - 1)][(int)(w_x / 64.0)] == '0')
		{
			wind->where= w_x;
			return ('S');
		}
		else
		{
			wind->where= w_y;
			return ('E');
		}
	}
	else if (wind->y_player <= w_y && wind->x_player >= w_x)
	{
		if ((int)(w_y) % 64 == 0 && wind->map[(int)((w_y / 64.0) - 1)][(int)(w_x / 64.0)] == '0')
		{
			wind->where= w_x;
			return ('S');
		}
		else
		{
			wind->where= w_y;
			return ('W');
		}
	}
	return (0);
}
