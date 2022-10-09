/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:25:36 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/09 10:27:02 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char    *read_map(int fd)
{
    char    *join;
    char    *map;

    if (!fd)
    {
        printf("Error\n");
        exit(1);
    }
    join = ft_strdup("");
    map = get_next_line(fd);
    while (map)
    {
        join = ft_strjoin(join, map);
        map = get_next_line(fd);
    }
    return (join);
}


void	images_to_xpm(t_mlx *wind)
{
	int	height;
	int	width;

	wind->wall = "/Users/otoufah/Desktop/Cub3d_back/sprites/redbrick.xpm";
	wind->empty = "/Users/otoufah/Desktop/Cub3d_back/sprites/redbrick.xpm";
	wind->player = "/Users/otoufah/Desktop/Cub3d_back/sprites/redbrick.xpm";

	wind->xpm_wall = mlx_xpm_file_to_image(wind->mlx, wind->wall, &width, &height);
	wind->xpm_empty = mlx_xpm_file_to_image(wind->mlx, wind->empty, &width, &height);
	wind->xpm_player = mlx_xpm_file_to_image(wind->mlx, wind->player, &width, &height);
}

int	main(int ac, char **av)
{
	t_mlx	wind;

	int		fildes;
	if (ac == 2)
	{
		fildes = open(av[1], O_RDONLY);
		wind.map = ft_split(read_map(fildes), '\n');
		wind.mlx = mlx_init();
		images_to_xpm(&wind);
		wind.window = mlx_new_window(wind.mlx, 1920, 1080, "Cub3D");


		// wind.window = mlx_new_window(wind.mlx, 1920, 1080, "Cub2D");
		// wind.img = mlx_new_image(wind.mlx, 1920, 1080);
		// wind.addr = mlx_get_data_addr(wind.img, &wind.bits_per_pixel, &wind.line_length, &wind.endian);
		wind.field_of_view = 90;
		
		get_player_position(&wind);
		map_filling(&wind);
		mlx_hook(wind.window, 2, 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}
