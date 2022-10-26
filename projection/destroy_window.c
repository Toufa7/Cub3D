#include "../cub3d.h"

int	destroy_window(t_mlx *wind)
{
	mlx_destroy_window(wind->mlx, wind->window);
	exit(0);
}
