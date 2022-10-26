#include "../cub3d.h"

void	my_mlx_pixel_put(t_my_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color ;
}
