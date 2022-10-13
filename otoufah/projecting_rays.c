/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projecting_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:32 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/09 15:48:09 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	projecting_rays(t_mlx *wind)
{
	int		i;
	int		nbr_of_rays;
	float	player_view;

	i = -1;
	nbr_of_rays = 1920;
	player_view = wind->field_of_view - 32;
	while (++i <= nbr_of_rays)
	{
		cast_rays(wind, player_view, i);
		// printf("FOV -> %f\n", wind->field_of_view);
		// printf("X Player -> %f\n", wind->x_player);
		// printf("Y Player -> %f\n", wind->y_player);
		// printf("Player View -> %f\n", player_view);
		// printf("Idx-> %i\n", i);
		player_view += 0.03333333333;
	}
}
