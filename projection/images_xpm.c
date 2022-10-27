#include "../cub3d.h"

void	images_to_xpm(t_mlx *wind)
{
	int	h;
	int	w;

	wind->n_img = wind->parsing->north_path;
	wind->s_img = wind->parsing->south_path;
	wind->e_img = wind->parsing->east_path;
	wind->w_img = wind->parsing->west_path;
	wind->n_xpm = mlx_xpm_file_to_image(wind->mlx, wind->n_img, &w, &h);
	wind->s_xpm = mlx_xpm_file_to_image(wind->mlx, wind->n_img, &w, &h);
	wind->e_xpm = mlx_xpm_file_to_image(wind->mlx, wind->n_img, &w, &h);
	wind->w_xpm = mlx_xpm_file_to_image(wind->mlx, wind->n_img, &w, &h);
	wind->my_mlx.addr_n = mlx_get_data_addr(wind->n_xpm, &wind->my_mlx.bpp_n,
			&wind->my_mlx.l_len_n, &wind->my_mlx.endian_n);
	wind->my_mlx.addr_s = mlx_get_data_addr(wind->s_xpm, &wind->my_mlx.bpp_s,
			&wind->my_mlx.l_len_s, &wind->my_mlx.endian_s);
	wind->my_mlx.addr_w = mlx_get_data_addr(wind->w_xpm, &wind->my_mlx.bpp_w,
			&wind->my_mlx.l_len_w, &wind->my_mlx.endian_w);
	wind->my_mlx.addr_e = mlx_get_data_addr(wind->e_xpm, &wind->my_mlx.bpp_e,
			&wind->my_mlx.l_len_e, &wind->my_mlx.endian_e);
}
