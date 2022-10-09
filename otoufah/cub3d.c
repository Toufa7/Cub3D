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
        // ft_free(map);
    }
    // ft_free(map);
    return (join);
}


void	images_to_xpm(t_mlx *wind)
{
	int	height;
	int	width;

	wind->wall = "sprites/redbrick.xpm";
	wind->empty = "sprites/redbrick.xpm";
	wind->player = "sprites/redbrick.xpm";

	
	wind->xpm_wall = mlx_xpm_file_to_image(wind->mlx, wind->wall, &width, &height);
	wind->xpm_empty = mlx_xpm_file_to_image(wind->mlx, wind->empty, &width, &height);
	wind->xpm_player = mlx_xpm_file_to_image(wind->mlx, wind->player, &width, &height);
}


void	check_extension(char *av[])
{
	if (strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
	{
		printf("Provide a .cub file\n");
		exit(1);
	}
}

void	check_existing(char *av[])
{
	if (strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
	{
		printf("Provide a .cub file\n");
		exit(1);
	}
}

void	creating_window(t_mlx *wind)
{
	int	height;
	int	width;

	height = 1920;
	width = 1080;
	wind->window = mlx_new_window(wind->mlx, height, width, "Cub2D");
}


int	main(int ac, char **av)
{
	t_mlx	wind;

	int		fildes;
	if (ac == 2)
	{
		fildes = open(av[1], O_RDONLY);
		if (fildes == -1)
		{
			printf("Error\n");
			exit(0);
		}
		wind.map = ft_split(read_map(fildes), '\n');
		wind.mlx = mlx_init();
		check_extension(av);
		wind.window = mlx_new_window(wind.mlx, 1920, 1080, "Cub2D");
		wind.img = mlx_new_image(wind.mlx, 1920, 1080);
		wind.addr = mlx_get_data_addr(wind.img, &wind.bits_per_pixel, &wind.line_length, &wind.endian);
		images_to_xpm(&wind);
		get_player_position(&wind);
		wind.field_of_view = 360;
		map_filling(&wind);
		mlx_hook(wind.window, 2, 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}
