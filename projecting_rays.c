/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projecting_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:32 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:50:33 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	projecting_rays(t_mlx *wind)
{
	int		i;
	int		nbr_of_rays;
	float	player_view;

	i = -1;
	nbr_of_rays = 60;
	// Dividing my view into 2 triangle 32° left and 32° right
	player_view = wind->field_of_view - 32;
	// printf("Field Of View => %f\n", player_view);
	while (++i <= nbr_of_rays)
	{
		cast_rays(wind, player_view);
		player_view += 60 / 60;
	}
}
