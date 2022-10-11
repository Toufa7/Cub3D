/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:51 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:50:51 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_filling(t_mlx	*wind)
{
	projecting_rays(wind);
	//printf("Player Current Pos -> [%f,%f]\n", wind->x_player, wind->y_player);
}
