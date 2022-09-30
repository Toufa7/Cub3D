/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:25:36 by otoufah           #+#    #+#             */
/*   Updated: 2022/09/30 08:40:24 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_map(int fd)
{
	char	*join;
	char	*map;

	join = ft_strdup("");
	map = get_next_line(fd);
	while (map)
	{
		join = ft_strjoin(join, map);
		map = get_next_line(fd);
		free(map);
	}
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
				wind->ystep = i * 60;
				wind->xstep = j * 60;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	drawing_rays(t_window *wind, float i)
{
	double	px;
	double	py;
	int		distance_ray;
	int		mx;
	int		my;

	px = wind->xstep;
	py = wind->ystep;
	distance_ray = 0;
	while (1)
	{
		mx = (int)px / 60.0;
		my = (int)py / 60.0;
		if (wind->map[my][mx] == '1')
			break ;
		px += cos((i) * M_PI / 180) * 1;
		py += sin((i) * M_PI / 180) * 1;
		mlx_pixel_put(wind->mlx, wind->window, px, py, 0XFF2D0F);
	}
}

void	map_filling(t_window  *wind)
{
	int		j;
	int		i;
	int		idx;
	float	player_view;
	
	i = 0;
	while (wind->map[i])
	{
		j = 0;
		while (wind->map[i][j])
		{
			if (wind->map[i][j] == '1')
				mlx_put_image_to_window(wind->mlx, wind->window, wind->wall_1, j * 60, i * 60);
			else if (wind->map[i][j] == '0')
				mlx_put_image_to_window(wind->mlx, wind->window, wind->empty_1, j * 60, i * 60);
			else if (wind->map[i][j] == 'P')
			{
				wind->map[i][j] = '0';
				mlx_put_image_to_window(wind->mlx, wind->window, wind->empty_1, j * 60, i * 60);
			}
			j++;
		}
		i++;
	}
	mlx_string_put(wind->mlx, wind->window, wind->xstep, wind->ystep, 0X000000 ,"#");

	idx = 0;
	player_view = wind->field_of_view - 30;
	// if (player_view > 360)
	// 	player_view -= 360;
	// if (player_view < 360)
	// 	player_view += 360;
	while (idx <= 64)
	{
		drawing_rays(wind, player_view);
		player_view += 64.0/64.0;
		idx++;
		if (player_view > 360)
			player_view -= 360;
		if (player_view < 360)
			player_view += 360;
	}
	
}

void    right(t_window *wind)
{
	wind->field_of_view += 10;
	if (wind->field_of_view > 360)
		wind->field_of_view -= 360;
	if (wind->field_of_view < 360)
		wind->field_of_view += 360;
}

void    left(t_window *wind)
{
	wind->field_of_view -= 10;
	if (wind->field_of_view > 360)
		wind->field_of_view -= 360;
	if (wind->field_of_view < 360)
		wind->field_of_view += 360;
}

void    up(t_window *wind)
{
	double px;
	double py;
	
	py = sin(wind->field_of_view * M_PI/180) * 5;
	px = cos(wind->field_of_view * M_PI/180) * 5;
	if (wind->map[(int)(wind->ystep + py * 2) / 60][(int)(wind->xstep + px * 2) / 60] == '0')
	{
		wind->xstep += px;
		wind->ystep += py;
	}
}

void    down(t_window *wind)
{

	double  px;
	double  py;

	py = sin(wind->field_of_view * M_PI/180) * 5;
	px = cos(wind->field_of_view * M_PI/180) * 5;
	if (wind->map[(int)(wind->ystep - py * 2) / 60 ][(int)(wind->xstep - px * 2)/ 60] == '0')
	{
		wind->xstep -= px;
		wind->ystep -= py;
	}
}


int get_keys(int press, t_window *wind)
{
	if (press == 124	)
		right(wind);
	if (press == 123)
		left(wind);
	if (press == 126)
		up(wind);
	if (press == 125)
		down(wind);
	if (press == 53)
	{
		mlx_destroy_window(wind->mlx, wind->window);
		exit (0);
	}
	map_filling(wind);
	return (0);
}

void    creating_window(t_window *wind)
{
	int height;
	int width;

	height = 60 * 25;
	width = 60 * 7;
	wind->window = mlx_new_window(wind->mlx, height, width, "Cub2D");
}

int destroy_window(t_window *wind)
{
	mlx_destroy_window(wind->mlx, wind->window);
	exit(0);
}

int main(int ac, char **av)
{
	t_window wind;

	if (ac == 2)
	{
		wind.map = ft_split(read_map(open(av[1], O_RDONLY)), '\n');
		wind.mlx = mlx_init();
		creating_window(&wind);
		images_to_xpm(&wind);
		get_player_position(&wind);
		// viewing angle the area that the lpayer can see 60°
		wind.field_of_view = 90;
		map_filling(&wind);
		mlx_hook(wind.window, 2,0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window ,&wind);
		mlx_loop(&wind);
	}
	else
		printf("Check Nbr Of Args");
}
