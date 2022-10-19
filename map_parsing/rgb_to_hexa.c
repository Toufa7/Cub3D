/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:18:38 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/19 16:44:37 by orbiay           ###   ########.fr       */
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

	split = ft_split(ft_strdup(str), ',');
	return (rgb(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2])));
}
