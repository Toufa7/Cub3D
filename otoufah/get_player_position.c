/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:13 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:50:14 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_player_position(t_mlx *wind)
{
	int	i;
	int	j;

	i = 0;
	while (wind->map[i])
	{
		j = 0;
		while (wind->map[i][j])
		{
			if (wind->map[i][j] == 'N' || wind->map[i][j] == 'S' || wind->map[i][j] == 'W' || wind->map[i][j] == 'E')
			{
				if (wind->map[i][j] == 'N')
					wind->field_of_view = 270;
				else if (wind->map[i][j] == 'S')
					wind->field_of_view = 90;
				else if (wind->map[i][j] == 'E')
					wind->field_of_view = 360;
				else if (wind->map[i][j] == 'W')
					wind->field_of_view = 180;
				wind->map[i][j] = '0';
				wind->y_player = i * 64;
				wind->x_player = j * 64;
				break ;
			}
			j++;
		}
		i++;
	}
}
