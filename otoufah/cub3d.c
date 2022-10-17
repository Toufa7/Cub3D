/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:25:36 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/13 19:21:16 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


// TODO:
// {
// 	[✅] Fixing 3D Rendring Strips
// 	[✅] Handling More than 2 comma in rgb
// 	[❌] Handling newlines inside the map
// 	[❌] Convert RGB color to hexadecimal
// 	[✅] Don't forget to exit if an error happend
// }

int	main(int ac, char **av)
{
	t_mlx	wind;

	wind.parsing = read_and_add(av);

	// printf("Path 1-> %s\n", wind.parsing.NO);
	// printf("Path 2-> %s\n", wind.parsing.SO);
	// printf("Path 3-> %s\n", wind.parsing.WE);
	// printf("Path 4-> %s\n", wind.parsing.EA);
	// printf("Ceiling -> %s\n", wind.parsing.C);
	// printf("Floor -> %s\n", wind.parsing.F);
	printf("Full Map -> \n%s", wind.parsing.full_map);
	 exit(0);
	if (ac == 2)
	{
		wind.map = ft_split(wind.parsing.full_map, '\n');
		wind.mlx = mlx_init();
		wind.window = mlx_new_window(wind.mlx, 1920, 1080, "Cub3D");
        get_player_position(&wind);	
        map_filling(&wind);
        mlx_hook(wind.window, 2, 0, get_keys, &wind);
        mlx_hook(wind.window, 17, 0, destroy_window, &wind);
        mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}
//handle more than coma