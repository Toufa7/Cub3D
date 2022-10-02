/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:50:55 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/02 09:50:56 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_map(int fd)
{
	char	*join;
	char	*map;

	if (!fd)
	{
		printf("Error\n");
		exit(1);
	}
	join = ft_strdup("");
	map = get_next_line(fd);
	while (map)
	{
		join = ft_strjoin(join, map);
		map = get_next_line(fd);
		ft_free(map);
	}
	ft_free(map);
	return (join);
}
