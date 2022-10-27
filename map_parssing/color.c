/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:08:13 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/27 18:22:04 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parssing.h"

// void	print_data(t_data_par *parsing)
// {
// 	printf("floor_color  %d \n", parsing->floor_color);
// 	printf("ciling_color %d \n", parsing->ciling_color);
// 	printf("north_path   %s \n", parsing->north_path);
// 	printf("south_path   %s \n", parsing->south_path);
// 	printf("east_path    %s \n", parsing->east_path);
// 	printf("west_path    %s \n", parsing->west_path);

// 	for (size_t i = 0; parsing->maze[i] != '\0'; i++)
// 	{
// 		printf(" %s\n", parsing->maze[i]);
// 	}
// }

int	stat_color(char s, int *vergul, int *nbr, int *rgb)
{
	if (s >= '0' && s <= '9')
		(*nbr) = (*nbr) * 10 + s - '0';
	else if (s == ',')
	{
		if ((*vergul) < 3)
			rgb[(*vergul)] = *nbr;
		(*vergul)++;
		(*nbr) = 0;
	}
	else if (s != ' ')
	{
		*vergul = 0;
		return (0);
	}
	return (1);
}

int	check_verg(char *line)
{
	int	index;
	int	vergul;
	int	nbr;
	int	c[3];

	index = 0;
	vergul = 0;
	nbr = 0;
	while (line[index])
	{
		if (stat_color(line[index], &vergul, &nbr, c) == 0)
			break ;
		index++;
	}
	if (vergul == 2 && c[0] <= 255 && c[1] <= 255 && nbr <= 255)
		return (256 * 256 * c[0] + 256 * c[1] + nbr);
	return (-1);
}

int	ft_get_color(char *line, char *str)
{
	char	*str_color;
	int		color;

	color = -1;
	str_color = ft_strtrim(line, str);
	if (str_color[0] != ',' && str_color[ft_strlen(str_color) - 1] != ',')
		color = check_verg(str_color);
	if (color == -1)
		error_color();
	free(line);
	free(str_color);
	return (color);
}

void	get_color_values(t_data_par *parsing, char *line, t_index *index)
{
	if (!ft_strncmp(line, "F ", 2))
		parsing->floor_color = ft_get_color(line, " F");
	else if (!ft_strncmp(line, "C ", 2))
		parsing->ciling_color = ft_get_color(line, " C");
	index->n_color++;
}
