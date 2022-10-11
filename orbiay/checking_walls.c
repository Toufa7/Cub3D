/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:30:44 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/10 14:05:37 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	all_walls(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char	*str, int start, int count)
{
	int	len;

	len = ft_strlen(str);
	if (start == 6 || start == (count - 1))
	{
		if (!all_walls(str))
		{
			printf("Error : There is a problem in Row[%d]", start);
			return (0);
		}
	}
	if (str[len - 1] != '1' && str[len - 1] != ' ' )
	{
		printf("Error : There is a problem in Row[%d][%d]", start, len);
		return (0);
	}
	if (str[0] != '1' && str[0] != ' ')
	{
		printf("Error : There is a problem in Row[%d][%d]", start, 0);
		return (0);
	}
	return (1);
}
