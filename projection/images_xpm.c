#include "../cub3d.h"

void    images_to_xpm(t_mlx *wind)
{
    // int height;
    // int width;

    wind->north_img = wind->parsing.NO;
    wind->south_img = wind->parsing.SO;
    wind->west_img  = wind->parsing.WE;
    wind->east_img  = wind->parsing.EA;

    printf("We -> %s\n", wind->west_img);
    printf("No -> %s\n", wind->north_img);
    printf("So -> %s\n", wind->south_img);
    printf("Ea -> %s\n", wind->east_img);
    
    // wind->north_xpm = mlx_xpm_file_to_image(wind->mlx, wind->north_img ,&width, &height);
    // wind->south_xpm = mlx_xpm_file_to_image(wind->mlx, wind->south_img ,&width, &height);
    // wind->west_xpm  = mlx_xpm_file_to_image(wind->mlx, wind->west_img ,&width, &height);
    // wind->east_xpm  = mlx_xpm_file_to_image(wind->mlx, wind->east_img ,&width, &height);
}

