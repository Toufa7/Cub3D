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

void	images_to_xpm(t_window *wind)
{
	int	height;
	int	width;

	wind->wall = "./sprites/black.xpm";
	wind->empty = "./sprites/white.xpm";
	wind->player = "./sprites/player.xpm";
	wind->wall_1 = mlx_xpm_file_to_image(wind->mlx, wind->wall, &width, &height);
	wind->empty_1 = mlx_xpm_file_to_image(wind->mlx, wind->empty, &width, &height);
	wind->player_1 = mlx_xpm_file_to_image(wind->mlx, wind->player, &width, &height);
}

void	get_player_position(t_window *wind)
{
	int	i;
	int	j;

	i = 0;
	while (wind->map[i])
	{
		j = 0;
		while (wind->map[i][j])
		{
			if (wind->map[i][j] == 'P')
			{
				wind->map[i][j] = '0';
				wind->ystep = i * 60;
				wind->xstep = j * 60;
				break ;
			}
			j++;
		}
		i++;
	}
}

double	degrees_to_radians(t_window *wind)
{
	// wind->field_of_view = Angle Degree which is 64
	return (wind->field_of_view * M_PI / 180);
}

void	cast_rays(t_window *wind, float nbr_ray)
{
	double	px;
	double	py;
	int		distance_ray;
	int		p_x;
	int		p_y;
	int		dis_between_each_pix;

	px = wind->xstep;
	py = wind->ystep;
	dis_between_each_pix = 2;
	distance_ray = 0;
	while (distance_ray < 60 * (38 - 2 / 2))
	{
		// Getting Player postion in the Map dividing
		p_x = (int)px / 60;
		p_y = (int)py / 60;
		if (wind->map[p_y][p_x] == '1')
			break ;
		px += cos((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		py += sin((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		mlx_pixel_put(wind->mlx, wind->window, px, py, RED);
		distance_ray++;
	}
}

void	projecting_rays(t_window *wind)
{
	int		i;
	int		nbr_of_rays;
	float	player_view;

	i = -1;
	nbr_of_rays = 64;
	// Dividing my view into 2 triangle 32° left and 32° right
	player_view = wind->field_of_view - 32;
	while (++i <= nbr_of_rays)
	{
		cast_rays(wind, player_view);
		player_view += 64 / 64;
	}
}

void	map_filling(t_window	*wind)
{
	int		j;
	int		i;

	i = 0;
	while (wind->map[i])
	{
		j = 0;
		while (wind->map[i][j])
		{
			if (wind->map[i][j] == '1')
				mlx_put_image_to_window(wind->mlx, wind->window, wind->wall_1, j * 60, i * 60);
			else if (wind->map[i][j] == '0' || wind->map[i][j] == 'P')
				mlx_put_image_to_window(wind->mlx, wind->window, wind->empty_1, j * 60, i * 60);
			j++;
		}
		i++;
	}
	mlx_string_put(wind->mlx, wind->window, wind->xstep, wind->ystep, BLUE, "(-_-)");
	projecting_rays(wind);
}

void	right(t_window *wind)
{
	wind->field_of_view += 5;
	if (wind->field_of_view > 360)
		wind->field_of_view -= 360;
	if (wind->field_of_view < 360)
		wind->field_of_view += 360;
}

void	left(t_window *wind)
{
	wind->field_of_view -= 5;
	if (wind->field_of_view > 360)
		wind->field_of_view -= 360;
	if (wind->field_of_view < 360)
		wind->field_of_view += 360;
}

void	move_forward(t_window *wind)
{
	double	px;
	double	py;

	py = sin(degrees_to_radians(wind)) * 5;
	px = cos(degrees_to_radians(wind)) * 5;
	if (wind->map[(int)(wind->ystep + py * 2) / 60][(int)(wind->xstep + px * 2) / 60] == '0')
	{
		wind->xstep += px;
		wind->ystep += py;
	}
}

void	move_backword(t_window *wind)
{
	double	px;
	double	py;


	py = sin(degrees_to_radians(wind)) * 5;
	px = cos(degrees_to_radians(wind)) * 5;
	if (wind->map[(int)(wind->ystep - py * 2) / 60][(int)(wind->xstep - px * 2) / 60] == '0')
	{
		wind->xstep -= px;
		wind->ystep -= py;
	}
}

int	get_keys(int press, t_window *wind)
{
	if (press == 124)
		right(wind);
	if (press == 123)
		left(wind);
	if (press == 126)
		move_forward(wind);
	if (press == 125)
		move_backword(wind);
	if (press == 53)
	{
		mlx_destroy_window(wind->mlx, wind->window);
		exit (0);
	}
	map_filling(wind);
	return (0);
}

void	creating_window(t_window *wind)
{
	int	height;
	int	width;

	height = 60 * 38;
	width = 60 * 11;
	wind->window = mlx_new_window(wind->mlx, height, width, "Cub2D");
}

int	destroy_window(t_window *wind)
{
	mlx_destroy_window(wind->mlx, wind->window);
	exit(0);
}

int	main(int ac, char **av)
{
	t_window	wind;

	if (ac == 2)
	{
		int fildes = open(av[1], O_RDONLY);
		if (!fildes)
		{
			printf("Error\n");
			exit(0);
		}
		wind.map = ft_split(read_map(fildes), '\n');
		wind.mlx = mlx_init();
		if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
		{
			printf("Provide a .cub file\n");
			exit(1);
		}
		creating_window(&wind);
		images_to_xpm(&wind);
		get_player_position(&wind);
		wind.field_of_view = 0;
		map_filling(&wind);
		mlx_hook(wind.window, 2, 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}