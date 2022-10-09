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

#include "cub3d.h"


// void	images_to_xpm(t_mlx *wind)
// {
// 	// int	height;
// 	// int	width;


	

// 	// wind->wall = "./sprites/redbrick.xpm";
// 	// wind->empty = "./sprites/Stone_1.xpm";
// 	// wind->player = "./sprites/player.xpm";
// 	// wind->xpm_wall = mlx_xpm_file_to_image(wind->mlx, wind->wall, &width, &height);
// 	// wind->xpm_empty = mlx_xpm_file_to_image(wind->mlx, wind->empty, &width, &height);
// 	// wind->xpm_player = mlx_xpm_file_to_image(wind->mlx, wind->player, &width, &height);
// }

void	check_extension(char *av[])
{
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
	{
		printf("Provide a .cub file\n");
		exit(1);
	}
}


int	main(int ac, char **av)
{
	t_mlx	*wind;
	int		fildes;

	wind = malloc(sizeof(t_mlx));
	if (ac == 2)
	{
		fildes = open(av[1], O_RDONLY);
		if (fildes == -1)
		{
			printf("Error\n");
			exit(0);
		}
		wind->map = ft_split(read_map(fildes), '\n');
		wind->mlx = mlx_init();
		// check_extension(av);
		wind->window = mlx_new_window(wind->mlx, 1920, 1080, "Cub2D");
		wind->data.img = mlx_new_image(wind->mlx, 1920, 1080);
		wind->data.addr = mlx_get_data_addr(wind->data.img, &wind->data.bits_per_pixel, &wind->data.line_length, &wind->data.endian);
		get_player_position(wind);
		wind->field_of_view = 360;
		map_filling(wind);
		mlx_hook(wind->window, 2, 0, get_keys, wind);
		mlx_hook(wind->window, 17, 0, destroy_window, wind);
		mlx_loop(wind);
	}
	else
		printf("Nbr of Args");
}
