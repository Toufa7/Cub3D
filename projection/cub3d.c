/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:25:36 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/22 12:20:47 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* TODO:
// {
			Poms
// 	[✅] Fixing 3D Rendring Strips
// 	[✅] Fixing seeing between 2 walls
// 	[✅] Fixing fisheye effect
// 	[✅] Fixing keys

// 	[✅] Adding colors to wall
// 	[❌] Fixing colors between walls
// 	[❌] Adding textures

			Oussama
// 	[✅] Handling More than 2 comma in rgb
// 	[✅] Handling newlines inside the map
// 	[✅] Convert RGB color to hexadecimal
// 	[✅] Don't forget to exit if an error happend
// 	[✅] Leaks
*/

int	main(int ac, char **av)
{
	t_mlx	wind;

	wind.parsing = read_and_add(av);
	wind.ceilling = rgb_to_hexa(wind.parsing.C);
	wind.floor = rgb_to_hexa(wind.parsing.F);
	images_to_xpm(&wind);
	if (ac == 2)
	{
		wind.map = ft_split(wind.parsing.full_map, '\n');
		wind.mlx = mlx_init();
		wind.window = mlx_new_window(wind.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
		get_player_position(&wind);
		projecting_rays(&wind);
		mlx_hook(wind.window, 2, 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}
