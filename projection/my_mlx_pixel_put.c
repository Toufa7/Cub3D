/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:08:59 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/14 10:09:01 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	The images divided into small squares called pixels
	and each pixel requires 1 bit of memory
	we're working with RGB (0-255) each color takes 8 bits
	in total that's 24 bits
	
*/

void	my_mlx_pixel_put(t_my_mlx *data, int x, int y, int color)
{
	char	*dst;

	// printf("X	=> %d\n", x);
	// printf("Y	=> %d\n", y);
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color ;
}
