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

	wind->wall = "./sprites/black.xpm";
	wind->clear = "./sprites/white.xpm";
	wind->player = "./sprites/player.xpm";
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
	// wind->field_of_view = Angle Degree which is 60
	return (wind->field_of_view * M_PI / 180);
}

void	cast_rays(t_mlx *wind, float nbr_ray)
{
	double	px;
	double	py;
	int		distance_ray;
	int		p_x;
	int		p_y;
	double		dis_between_each_pix;

	px = wind->x_player;
	py = wind->y_player;
	dis_between_each_pix = 1;
	distance_ray = 0;
	while (1)
	{
		p_x = (int)px / 60;
		p_y = (int)py / 60;
		if (wind->map[p_y][p_x] == '1')
		{
			printf("Pos -> [%d,%d]\n", p_y, p_x);
			break ;
		}
		px += cos((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		py += sin((nbr_ray) * M_PI / 180) * dis_between_each_pix;
		mlx_pixel_put(wind->mlx, wind->window, px, py, RED);
	}
}

void	projecting_rays(t_mlx *wind)
{
	int		i;
	int		nbr_of_rays;
	float	player_view;

	i = -1;
	nbr_of_rays = 60;
	// Dividing my view into 2 triangle 32° left and 32° right
	player_view = wind->field_of_view;
	while (i++ < nbr_of_rays)
	{
		cast_rays(wind, player_view);
		player_view += 1;
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
	mlx_string_put(wind->mlx, wind->window, wind->x_player, wind->y_player, BLUE, "(-_-)");
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

	py = sin(degrees_to_radians(wind)) * 1;
	px = cos(degrees_to_radians(wind)) * 1;
	if (wind->map[(int)(wind->y_player + py * 2) / 60][(int)(wind->x_player + px * 2) / 60] == '0')
	{
		wind->x_player += px;
		wind->y_player += py;
	}
}

void	move_backword(t_mlx *wind)
{
	double	px;
	double	py;


	py = sin(degrees_to_radians(wind)) * 1;
	px = cos(degrees_to_radians(wind)) * 1;
	if (wind->map[(int)(wind->y_player - py * 2) / 60][(int)(wind->x_player - px * 2) / 60] == '0')
	{
		wind->x_player -= px;
		wind->y_player -= py;
	}
}

int	get_keys(int press, t_mlx *wind)
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

void	creating_window(t_mlx *wind)
{
	int	height;
	int	width;

	height = 60 * 16;
	width = 60 * 5;
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