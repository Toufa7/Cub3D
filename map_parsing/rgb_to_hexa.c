/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:18:38 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/22 12:14:07 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	rgb(int r, int g, int b)
{
	int	final;

	final = (r << 16) + (g << 8) + b;
	return (final);
}

int	rgb_to_hexa(char *str)
{
	char	**split;
	int		ret_rgb;

	split = ft_split(str, ',');
	ret_rgb = rgb(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
	ft_free(split);
	return (ret_rgb);
}
