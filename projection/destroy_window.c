/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:16:47 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/28 12:17:41 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy_window(t_mlx *wind)
{
	mlx_destroy_window(wind->mlx, wind->window);
	printf("Fes Hakma L3alam\n");
	exit(0);
}
