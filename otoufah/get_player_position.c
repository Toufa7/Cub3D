/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:13 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/09 15:47:40 by orbiay           ###   ########.fr       */
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
			if (wind->map[i][j] == 'P')
			{
				// printf("Found\b");
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
