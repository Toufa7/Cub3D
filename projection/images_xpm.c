#include "../cub3d.h"

void    images_to_xpm(t_mlx *wind)
{
    int height;
    int width;

    wind->north_xpm = mlx_xpm_file_to_image(wind->mlx, "./sprites/xpm_images/north.xpm", &width, &height);
    wind->south_xpm = mlx_xpm_file_to_image(wind->mlx, "./sprites/xpm_images/south.xpm", &width, &height);
    wind->east_xpm = mlx_xpm_file_to_image(wind->mlx, "./sprites/xpm_images/west_1.xpm", &width, &height);
    wind->west_xpm = mlx_xpm_file_to_image(wind->mlx, "./sprites/xpm_images/east_1.xpm", &width, &height);
    wind->my_mlx.addr_n = mlx_get_data_addr(wind->north_xpm, &wind->my_mlx.bpp_n, &wind->my_mlx.line_len_n, &wind->my_mlx.endian_n);
    wind->my_mlx.addr_s = mlx_get_data_addr(wind->south_xpm, &wind->my_mlx.bpp_s, &wind->my_mlx.line_len_s, &wind->my_mlx.endian_s);
    wind->my_mlx.addr_w = mlx_get_data_addr(wind->west_xpm, &wind->my_mlx.bpp_w, &wind->my_mlx.line_len_w, &wind->my_mlx.endian_w);
    wind->my_mlx.addr_e = mlx_get_data_addr(wind->east_xpm, &wind->my_mlx.bpp_e, &wind->my_mlx.line_len_e, &wind->my_mlx.endian_e);
}