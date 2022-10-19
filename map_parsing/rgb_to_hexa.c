/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:18:38 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/18 16:02:20 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

char	*without_comma(char *str)
{
	char	*ret_str;
	int		i;
	int		j;

	ret_str = malloc(ft_strlen(str) - 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			i++;
		else
		{
			ret_str[j] = str[i];
			i++;
			j++;
		}
	}
	ret_str[j] = 0;
	return (ret_str);
}

int	rgb_to_hexa(char *str)
{
	str = without_comma(str);
	//printf("%s", str);
	
	return (0);
}
