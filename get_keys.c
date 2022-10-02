/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:08 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:50:09 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_keys(int press, t_mlx *wind)
{
	if (press == 123 || press == 0)
		move_left(wind);
	if (press == 124 || press == 2)
		move_right(wind);
	if (press == 125 || press == 1)
		move_backword(wind);
	if (press == 126 || press == 13)
		move_forward(wind);
	if (press == 53)
        destroy_window(wind);
	map_filling(wind);
	return (0);
}
