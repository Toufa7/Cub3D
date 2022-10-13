/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:05:14 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/10 15:36:16 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	check_no(char	**str)
{
	if (!strcmp(str[0], "NO") && counting(str) >= 2)
		return (1);
	return (0);
}

int	check_so(char	**str)
{
	if (!strcmp(str[0], "SO") && counting(str) >= 2)
		return (1);
	return (0);
}

int	check_we(char	**str)
{
	if (!strcmp(str[0], "WE") && counting(str) >= 2)
		return (1);
	return (0);
}

int	check_ea(char	**str)
{
	if (!strcmp(str[0], "EA") && counting(str) >= 2)
		return (1);
	return (0);
}

int	check_f(char	**str)
{
	if (!strcmp(str[0], "F") && counting(str) == 2)
		return (1);
	return (0);
}