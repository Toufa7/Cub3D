#include "../cub3d.h"

char	set_direction_coin(double y_player, double x_player, double py, double px, t_mlx *wind)
{
	double ppy = ((py / 64) + 1);
	double ppx = ((px / 64));

	double ppyy = ((py / 64) - 1);
	double ppxx = ((px / 64));

	if (y_player > py && x_player > px)
	{
		if ((int)(py + 1) % 64 == 0 && wind->map[(int)((py / 64) + 1)] && wind->map[(int)(ppy)][(int)(ppx)] == '0')
		{
			wind->where= py;
			return ('A');
		}
		else
			wind->where= py;
			return ('A');
	}
	else if (y_player > py && x_player < px)
	{
		if ((int)(py + 1) % 64 == 0 && wind->map[(int)((py / 64) + 1)] && wind->map[(int)(ppy)][(int)(ppx)] == '0')
		{
			wind->where= py;
			return ('A');
		}
		else
		{
			wind->where = py;
			return ('A');
		}
	}
	else if (y_player <= py && x_player <= px)
	{
		if ((int)(py) % 64 == 0 && wind->map[(int)((py / 64) - 1)] && wind->map[(int)(ppyy)][(int)(ppxx)] == '0')
		{
			wind->where = py;
			return ('A');
		}
		else
		{
			wind->where = py;
			return ('A');
		}
	}
	else if (y_player <= py && x_player >= px)
	{
		if ((int)(py) % 64 == 0 && wind->map[(int)((py / 64) - 1)] && wind->map[(int)(ppyy)][(int)(ppxx)] == '0')
		{
			wind->where = py;
			return ('A');
		}
		else
		{
			wind->where = py;
			return ('A');
		}
	}
	return (0);
}