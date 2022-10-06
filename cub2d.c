/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:25:36 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/04 17:55:51 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	images_to_xpm(t_mlx *wind)
{
	int	height;
	int	width;

	wind->wall = "./sprites/black.xpm";
	wind->empty = "./sprites/white.xpm";
	wind->xpm_wall = mlx_xpm_file_to_image(wind->mlx, wind->wall, &width, &height);
	wind->xpm_empty = mlx_xpm_file_to_image(wind->mlx, wind->empty, &width, &height);
}


void	creating_window(t_mlx *wind)
{
	int	height;
	int	width;

	height = 60 * 38;
	width = 60 * 11;
	wind->window = mlx_new_window(wind->mlx, height, width, "Cub2D");
}

int	main(int ac, char **av)
{
	t_mlx	wind;

	if (ac == 2)
	{
		int fildes = open(av[1], O_RDONLY);
		if (!fildes)
		{
			printf("Error\n");
			exit(0);
		}
		wind.map = ft_split(read_map(fildes), '\n');
		wind.mlx = mlx_init();
		if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
		{
			printf("Provide a .cub file\n");
			exit(1);
		}
		creating_window(&wind);
		images_to_xpm(&wind);
		get_player_position(&wind);
		wind.field_of_view = 270;
		map_filling(&wind);
		mlx_hook(wind.window, 2, 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}