/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:28:24 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/13 19:19:54 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "../cub3d.h"

int	counting(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	len(char **str)
{
	int		i;
	int		j;
	int		sum;

	sum = 0;
	j = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		sum += j;
		i++;
	}
	return (sum);
}

char	*joining(char **str)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	*re_str;

	count = counting(str) - 1;
	k = 0;
	j = 0;
	i = 1;
	re_str = malloc(len(str) + 1 + count);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			re_str[k] = str[i][j];
			j++;
			k++;
		}
		if (count - 1 != 0)
		{
			re_str[k++] = ' ';
			count--;
		}
		i++;
	}
	re_str[k] = '\0';
	return (re_str);
}

int	check_c(char	**str)
{
	if (!strcmp(str[0], "C") && counting(str) == 2)
		return (1);
	return (0);
}

int	check_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		else if ((str[i] < '0' || str[i] > '9') && str[i] != ',')
		{
			printf("Error : Special character in your map plz fix it.");
			return (0);
		}
		i++;
	}
	if (count > 2)
	{
		printf("Error : There is a problem with comma\n");
		return (0);
	}
	return (1);
}
