 #include "../cub3d.h"

char	*north_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	y = ((int)(round((i + (mlx->projection_3d - WIN_H) \
	* (mlx->projection_3d > WIN_H) / 2) \
	* (1000.0 / mlx->projection_3d))) % 1000);
	mlx->color = mlx->my_mlx.addr_n \
	+ (y * mlx->my_mlx.l_len_n + x * (mlx->my_mlx.bpp_n / 8));
	return (mlx->color);
}

char	*south_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	y = ((int)(round((i + (mlx->projection_3d - WIN_H) \
	* (mlx->projection_3d > WIN_H) / 2) \
	* (1000.0 / mlx->projection_3d))) % 1000);
	mlx->color = mlx->my_mlx.addr_s \
	+ (y * mlx->my_mlx.l_len_s + x * (mlx->my_mlx.bpp_s / 8));
	return (mlx->color);
}

char	*east_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	y = ((int)(round((i + (mlx->projection_3d - WIN_H) \
	* (mlx->projection_3d > WIN_H) / 2) \
	* (1000.0 / mlx->projection_3d))) % 1000);
	mlx->color = mlx->my_mlx.addr_e \
	+ (y * mlx->my_mlx.l_len_e + x * (mlx->my_mlx.bpp_e / 8));
	return (mlx->color);
}

char	*west_texture(t_mlx *mlx, int i)
{
	int	x;
	int	y;

	x = (int)round(mlx->where);
	y = ((int)(round((i + (mlx->projection_3d - WIN_H) \
	* (mlx->projection_3d > WIN_H) / 2) \
	* (1000.0 / mlx->projection_3d))) % 1000);
	mlx->color = mlx->my_mlx.addr_w \
	+ (y * mlx->my_mlx.l_len_w + x * (mlx->my_mlx.bpp_w / 8));
	return (mlx->color);
}
