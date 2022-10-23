#include "cub2d.h"


int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

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
	}
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
	return ((wind->field_of_view + 90) * M_PI / 180);
}

char	set_direction(double y_player, double x_player, double py, double px, t_mlx *wind)
{
	double ppy = ((py / 60) + 1);
	double ppx = ((px / 60));

	double ppyy = ((py / 60) - 1);
	double ppxx = ((px / 60));

	if (y_player > py && x_player > px)
	{
		if ((int)(py + 1) % 60 == 0 && wind->map[(int)((py / 60) + 1)] && wind->map[(int)(ppy)][(int)(ppx)] == '0')
		{
			return ('N');
		}
		else
			return ('W');
	}
	else if (y_player > py && x_player < px)
	{
		if ((int)(py + 1) % 60 == 0 && wind->map[(int)((py / 60) + 1)] && wind->map[(int)(ppy)][(int)(ppx)] == '0')
		{
			return ('N');
		}
		else
			return ('E');
	}
	else if (y_player <= py && x_player <= px)
	{
		if ((int)(py) % 60 == 0 && wind->map[(int)((py / 60) - 1)] && wind->map[(int)(ppyy)][(int)(ppxx)] == '0')
			return ('S');
		else
			return ('E');
	}
	else if (y_player <= py && x_player >= px)
	{
		if ((int)(py) % 60 == 0 && wind->map[(int)((py / 60) - 1)] && wind->map[(int)(ppyy)][(int)(ppxx)] == '0')
			return ('S');
		else
			return ('W');
	}
	return (0);
	// printf("------------------------\n");
}

void	cast_rays(t_mlx *wind, double fov)
{
	double	px;
	double	py;
	char 	dir = '\0';

	px = wind->x_player;
	py = wind->y_player;
	while (TRUE)
	{
		//  || wind->map[(int)((py / 60) + 1)][(int)((px / 60)) + 1] == '1' || wind->map[(int)((py / 60) - 1)][(int)((px / 60) - 1)] == '1' || wind->map[(int)((py / 60) + 1)][(int)((px / 60) - 1)] == '1'
		if (wind->map[(int)((py / 60))][(int)((px / 60))] == '1')
		{
			// printf("Player	Positions	[%d,%d]\n",(int)wind->y_player,(int)wind->x_player);
			// printf("Wall	Positions	[%d,%d]\n",(int)((py)),(int)((px)));
			// printf("  ------------------------ \n");
			dir = set_direction(wind->y_player, wind->x_player, py, px, wind);
			// printf("Direction -> %c\n", dir);
			break ;
		}
		// mlx_pixel_put(wind->mlx, wind->window, px, py, RED);
		px += cos((fov) * M_PI / 180);
		py += sin((fov) * M_PI / 180);
	}

	if (dir == 'N')
		draw_line(wind->mlx, wind->window,wind->x_player,wind->y_player , px, py, BLUE);
	else if (dir == 'E')
		draw_line(wind->mlx, wind->window,wind->x_player,wind->y_player , px, py, RED);
	else if (dir == 'S')
		draw_line(wind->mlx, wind->window,wind->x_player,wind->y_player , px, py, WHITE);
	else if (dir == 'W')
		draw_line(wind->mlx, wind->window,wind->x_player,wind->y_player , px, py, GREEN);
}

void	projecting_rays(t_mlx *wind)
{
	int		i;
	int		nbr_of_rays;
	double	fov;

	i = -1;
	nbr_of_rays = 1920;
	fov = wind->field_of_view - 30;
	while (i++ < nbr_of_rays)
	{
		cast_rays(wind, fov);
		fov += 64.0 / nbr_of_rays;
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
	projecting_rays(wind);
}

void	right(t_mlx *wind)
{
	wind->field_of_view += 10;
	if (wind->field_of_view > 360)
		wind->field_of_view -= 360;
	if (wind->field_of_view < 360)
		wind->field_of_view += 360;
}

void	left(t_mlx *wind)
{
	wind->field_of_view -= 10;
	if (wind->field_of_view > 360)
		wind->field_of_view -= 360;
	if (wind->field_of_view < 360)
		wind->field_of_view += 360;
}

void	  move_forward(t_mlx *wind)
{
	double	px;
	double	py;

	py = sin(degrees_to_radians(wind)) * 10;
	px = cos(degrees_to_radians(wind)) * 10;
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


	py = sin(degrees_to_radians(wind)) * 10;
	px = cos(degrees_to_radians(wind)) * 10;
	if (wind->map[(int)((wind->y_player - py) / 60)][(int)(wind->x_player - px) / 60] == '0')
	{
		wind->x_player -= px;
		wind->y_player -= py;
	}
}

void	move_right(t_mlx *wind)
{
	double	px;
	double	py;

	py = sin(degrees_to_radians_1(wind)) * 10;
	px = cos(degrees_to_radians_1(wind)) * 10;
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

	py = sin(degrees_to_radians_1(wind)) * 10;
	px = cos(degrees_to_radians_1(wind)) * 10;
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

	height = 60 * 21;
	width = 60 * 9;
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
		wind.field_of_view = 230;
		map_filling(&wind);
		mlx_hook(wind.window, 2, 0, get_keys, &wind);
		mlx_hook(wind.window, 17, 0, destroy_window, &wind);
		mlx_loop(&wind);
	}
	else
		printf("Nbr of Args");
}