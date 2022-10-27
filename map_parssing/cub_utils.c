/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:46:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/27 15:37:50 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parssing.h"

int	true_line(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_possiblty(char c)
{
	if (c != ' ' && c != '1' && c != '0' && c != 'S'
		&& c != 'N' && c != 'E' && c != 'W')
		return (1);
	return (0);
}

int	check_possiblty_tex(char *line )
{
	if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "NO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
	{
		return (1);
	}
	return (0);
}

void	init(t_data_par *parsing)
{
	parsing->north_path = 0;
	parsing->south_path = 0;
	parsing->east_path = 0;
	parsing->west_path = 0;
	parsing->ciling_color = -1;
	parsing->floor_color = -1;
	parsing->maze = 0;
	parsing->nbr_lin = 0;
}

void	free_function(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}