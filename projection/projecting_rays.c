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
	double	player_view;

	i = -1;
	player_view = wind->field_of_view - 32;
	while (++i <= 1920)
	{
		cast_rays(wind, player_view, i);
		player_view += (64 / 1920);
	}
}
