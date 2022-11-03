/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:06:05 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/30 18:06:06 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	calculate_distance(double y_player, double x_player, double y_wall, double x_wall)
{
	return (sqrt(((x_player - x_wall) * (x_player - x_wall)) + ((y_player - y_wall) * (y_player - y_wall))));
}

double	fix_fisheye(t_mlx *mlx, double angle)
{
	mlx->corrected_distance = mlx->distance * cos((angle - mlx->field_of_view) * (M_PI / 180));
	return (mlx->corrected_distance);
}
