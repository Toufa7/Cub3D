/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:31:16 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/28 16:48:30 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parsing.h"

int	around_zero(t_data_par *parsing, int index, char *line, int i)
{
	if (i >= (int)(ft_strlen(parsing->maze[index + 1])) ||
			(parsing->maze[index + 1] == 0 ||
			index - 1 < 0 || line[i - 1] == ' ' ||
			line[i + 1] == ' ' || line[i + 1] == '\0'
			|| parsing->maze[index - 1][i] == ' ' ||
			parsing->maze[index + 1][i] == '\0' ||
			parsing->maze[index + 1][i] == ' '))
	{
		return (1);
	}
	return (0);
}

void	around_ps(t_data_par *parsing, int i, int index)
{
	if (parsing->maze[index + 1] == 0
		|| index - 1 < 0
		|| parsing->maze[index][i - 1] == ' ' ||
		parsing->maze[index][i + 1] == ' ' ||
		parsing->maze[index][i + 1] == '\0' ||
		parsing->maze[index - 1][i] == ' '
		|| parsing->maze[index + 1][i] == '\0' ||
		parsing->maze[index + 1][i] == ' ')
	{
		error_line(parsing);
	}
}
