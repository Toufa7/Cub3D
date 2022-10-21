/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:03:50 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/19 16:37:21 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

# define TRUE 1


# define RED 0XFF0000
# define WHITE 0XFFFFFF
# define BLACK 0X000000
# define PURPLE 0X800080
# define BLUE 0X0000FF
# define GREEN 0X00FF00


# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct fd
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	*full_map;
	int		color_c;
	int		color_f;
}	t_fd;

int		len(char **str);
void	ft_free(char **str);
int		check_c(char **str);
int		check_f(char **str);
int		check_so(char **str);
int		counting(char **str);
int		check_we(char **str);
char	*joining(char **str);
int		check_no(char **str);
char	*only_map(char *str);
int		check_ea(char **str);
int		all_walls(char	*str);
t_fd	take_path(char	*str);
int		rgb_to_hexa(char *str);
int		check_comma(char *str);
int		check_player(char str);
t_fd	read_and_add(char **av);
int		map_checking(char *str);
t_fd	read_and_add(char **av);
int		check_isdigit(char **sp);
int		check_newline(char *str);
int		map_checking2(char	*str);
int		last_touches(char	**str);
t_fd	file_dis(char *sp, char *s);
void	check_extension(char *av[]);
int		check_f_c(char	**str,	int line);
int		check_spaces(char **str, int start);
int		check_colors_valid(char *F, char *C);
int		check_textures(char **str,	int line);
int		req_zero(char **str, int start, int i);
int		check_walls(char *str, int start, int count);
int		first_six_lines(char *split_str,	int line);
int		check_walls(char	*str, int start, int count);

typedef struct s_my_mlx
{
/*
	The image to be used as parameter
*/
	void	*img;
/*
	The image to used
*/
	char	*addr;
/*
	The number of bytes required to express a color of pixel entered as arguments
*/
	int		bpp;
/*
	Nbr of bytes required to store one image horizontal line in memory (Provided as argument)
*/
	int		line_len;
	int		endian;
}	t_my_mlx;

typedef struct s_window
{
	void		*mlx;
	void		*window;
	char		**map;
	double		field_of_view;
	double		x_player;
	double		y_player;
	double		x_end_of_ray;
	double		y_end_of_ray;
	t_fd		parsing;
	t_my_mlx	my_mlx;
}	t_mlx;

char	*get_next_line(int fd);
/*
	Getting the player position in the map [y,x]
*/
void	get_player_position(t_mlx *wind);
/*
	Used to move the player forward by increasing his current position by 1px
*/
void	move_forward(t_mlx *wind);
/*
	Used to move the player backward by decreasing his current position by 1px
*/
void	move_backword(t_mlx *wind);
/*
	Used to move the player by -90 degree in ordre to move him left 
*/
void	move_left(t_mlx *wind);
/*
	Used to move the player by -90 degree in ordre to move him right
*/
void	move_right(t_mlx *wind);
void	cast_rays(t_mlx *wind, double angle, int i);
/*
	Starting from the player position we draw line using cast_rays()
*/
void	projecting_rays(t_mlx *wind);
/*
	When we mesured the distance we start rendring our world
*/
void	casting_3d(double distance, int i, t_mlx *mlx, char dir);
/*
	Whenever the user hit a key provide him wwith the move he requires
*/
int		get_keys(int press, t_mlx	*wind);
int		destroy_window(t_mlx *wind);
void	my_mlx_pixel_put(t_my_mlx *data, int x, int y, int color);

#endif
