/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:16:30 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/28 12:16:37 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_mlx		wind;
	t_data_par	*parsing;

	parsing = malloc(sizeof(t_data_par));
	ft_parsing(ac, av, parsing);
	wind.parsing = parsing;
	if (ac == 2)
	{
		wind.map = parsing->maze;
		wind.mlx = mlx_init();
		wind.window = mlx_new_window(wind.mlx, WIN_W, WIN_H, "Cub3D");
		images_to_xpm(&wind);
		get_player_position(&wind);
		projecting_rays(&wind);
		mlx_hook(wind.window, 2, 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}
