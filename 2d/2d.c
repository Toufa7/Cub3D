#include "cub2d.h"

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
		// ft_free(map);
	}
	// ft_free(map);
	return (join);
}

void	images_to_xpm(t_mlx *wind)
{
	int	height;
	int	width;

	wind->wall = "../sprites/2d_black.xpm";
	wind->clear = "../sprites/2d_white.xpm";
	wind->player = "../sprites/2d_player.xpm";
	wind->xpm_wall = mlx_xpm_file_to_image(wind->mlx, wind->wall, &width, &height);
	wind->xpm_clear = mlx_xpm_file_to_image(wind->mlx, wind->clear, &width, &height);
	wind->xpm_player = mlx_xpm_file_to_image(wind->mlx, wind->player, &width, &height);
}

void	get_player_position(t_mlx *wind)
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
				wind->y_player = i * 60;
				wind->x_player = j * 60;
				break ;
			}
			j++;
		}
		i++;
	}
}

double	degrees_to_radians(t_mlx *wind)
{
	return (wind->field_of_view * M_PI / 180);
}

double	degrees_to_radians_1(t_mlx *wind)
{
	return ((wind->field_of_view / 2) * M_PI / 180);
}

void	cast_rays(t_mlx *wind, double fov)
{
	double	px;
	double	py;

	px = wind->x_player;
	py = wind->y_player;
	while (TRUE)
	{
		if (wind->map[(int)((py + 1) / 60)][(int)((px + 1) / 60)] == '1')
			break ;
		if (wind->map[(int)((py) / 60)][(int)((px) / 60)] == '1')
			break ;
		px += cos((fov) * M_PI / 180);
		py += sin((fov) * M_PI / 180);
		mlx_pixel_put(wind->mlx, wind->window, px, py, RED);
	}
}

void	projecting_rays(t_mlx *wind)
{
	int		i;
	int		nbr_of_rays;
	double	fov;

	i = -1;
	nbr_of_rays = 1;
	// Dividing my view into 2 triangle 32° left and 32° right
	fov = wind->field_of_view;
	while (i++ < nbr_of_rays)
	{
		cast_rays(wind, fov);
		fov += 0.03;
	}
}

void	map_filling(t_mlx	*wind)
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
				mlx_put_image_to_window(wind->mlx, wind->window, wind->xpm_wall, j * 60, i * 60);
			else if (wind->map[i][j] == '0')
				mlx_put_image_to_window(wind->mlx, wind->window, wind->xpm_clear, j * 60, i * 60);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(wind->mlx, wind->window, wind->xpm_player, wind->x_player, wind->y_player);
	// mlx_string_put(wind->mlx, wind->window, wind->x_player, wind->y_player, BLUE, "*");
	projecting_rays(wind);
}

void	right(t_mlx *wind)
{
	wind->field_of_view += 5;
	if (wind->field_of_view > 360)
		wind->field_of_view -= 360;
	if (wind->field_of_view < 360)
		wind->field_of_view += 360;
}

void	left(t_mlx *wind)
{
	wind->field_of_view -= 5;
	if (wind->field_of_view > 360)
		wind->field_of_view -= 360;
	if (wind->field_of_view < 360)
		wind->field_of_view += 360;
}

void	move_forward(t_mlx *wind)
{
	double	px;
	double	py;

	py = sin(degrees_to_radians(wind));
	px = cos(degrees_to_radians(wind));
	if (wind->map[(int)(wind->y_player + py) / 60][(int)(wind->x_player + px) / 60] == '0')
	{
		wind->x_player += px;
		wind->y_player += py;
	}
}

void	move_backword(t_mlx *wind)
{
	double	px;
	double	py;


	py = sin(degrees_to_radians(wind));
	px = cos(degrees_to_radians(wind));
	if (wind->map[(int)(wind->y_player - py) / 60][(int)(wind->x_player - px) / 60] == '0')
	{
		wind->x_player -= px;
		wind->y_player -= py;
	}
}

void	move_right(t_mlx *wind)
{
	double	px;
	double	py;

	py = sin(degrees_to_radians_1(wind));
	px = cos(degrees_to_radians_1(wind));
	if (wind->map[(int)(wind->y_player + py) / 60][(int)(wind->x_player + px) / 60] == '0')
	{
		wind->x_player += px;
		wind->y_player += py;
	}
}

void	move_left(t_mlx *wind)
{
	double	px;
	double	py;


	py = sin(degrees_to_radians_1(wind));
	px = cos(degrees_to_radians_1(wind));
	if (wind->map[(int)(wind->y_player - py) / 60][(int)(wind->x_player - px) / 60] == '0')
	{
		wind->x_player -= px;
		wind->y_player -= py;
	}
}




int	get_keys(int press, t_mlx *wind)
{
	if (press == 2)
		right(wind);
	if (press == 0)
		left(wind);
	if (press == 126)
		move_forward(wind);
	if (press == 125)
		move_backword(wind);
	if (press == 124)
		move_right(wind);
	if (press == 123)
		move_left(wind);
	if (press == 53)
	{
		mlx_destroy_window(wind->mlx, wind->window);
		exit (0);
	}
	map_filling(wind);
	return (0);
}

void	creating_window(t_mlx *wind)
{
	int	height;
	int	width;

	height = 60 * 20;
	width = 60 * 6;
	wind->window = mlx_new_window(wind->mlx, height, width, "Cub2D");
}

int	destroy_window(t_mlx *wind)
{
	mlx_destroy_window(wind->mlx, wind->window);
	exit(0);
}

int	main(int ac, char **av)
{
	t_mlx	wind;
	int 	fildes;

	if (ac == 2)
	{
		fildes = open(av[1], O_RDONLY);
		wind.map = ft_split(read_map(fildes), '\n');
		wind.mlx = mlx_init();
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