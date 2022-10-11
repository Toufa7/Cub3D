/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:25:36 by otoufah           #+#    #+#             */
/*   Updated: 2022/09/30 09:01:58 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*read_map(int fd)
{
	char	*join;
	char	*map;

	if (!fd)
	{
		//printf("Error\n");
		exit(1);
	}
	join = ft_strdup("");
	map = get_next_line(fd);
	while (map)
	{
		join = ft_strjoin(join, map);
		map = get_next_line(fd);
	}
	return (join);
}


int	main(int ac, char **av)
{
	t_mlx	wind;
	int		fildes;

	// wind = malloc(sizeof(t_mlx));
	if (ac == 2)
	{
		fildes = open(av[1], O_RDONLY);
		wind.map = ft_split(read_map(fildes), '\n');
		wind.mlx = mlx_init();

		wind.window = mlx_new_window(wind.mlx, 1920, 1080, "Cub3D");

        wind.field_of_view = 90;
        get_player_position(&wind);
        map_filling(&wind);
        mlx_hook(wind.window, 2, 0, get_keys, &wind);
        mlx_hook(wind.window, 17, 0, destroy_window, &wind);
        mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}