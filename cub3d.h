/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:29:36 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/28 21:29:39 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./map_parsing/includ/map_parsing.h"

# define TRUE 1

# define RED	0XFF0000
# define WHITE	0XFFFFFF
# define BLACK	0X000000
# define PURPLE	0X800080
# define BLUE	0X0000FF
# define GREEN	0X00FF00

# define WALL_DIM 64.0
# define HALF_WALL 32.0

/*
	Represents the angular of our triangle
*/
# define THETA	64.0
/*
	Video Resolution
*/
# define WIN_W	1920.0
/*
	Video Resolution
*/
# define WIN_H	1080.0

/*
	Distance to move in pixels
*/
# define PX_MOVE	10.0

/*
	In ordre to rotate the player around 
*/
# define PX_ROTATION	10.0

typedef struct s_my_mlx
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	int		bpp_n;
	int		l_len_n;
	int		endian_n;

	int		bpp_s;
	int		l_len_s;
	int		endian_s;

	int		bpp_w;
	int		l_len_w;
	int		endian_w;

	int		bpp_e;
	int		l_len_e;
	int		endian_e;

	int		bpp_c;
	int		l_len_c;
	int		endian_c;

	char	*addr_n;
	char	*addr_s;
	char	*addr_w;
	char	*addr_e;
	char	*addr_c;
}	t_my_mlx;

typedef struct s_window
{
	void		*mlx;
	void		*window;
	char		**map;
	int			width;
	int			height;

	char		*n_img;
	char		*s_img;
	char		*e_img;
	char		*w_img;

	char		*n_xpm;
	char		*s_xpm;
	char		*e_xpm;
	char		*w_xpm;

	double		field_of_view;

	double		x_player;
	double		y_player;

	double		x_step;
	double		y_step;

	int			x_m;
	int			y_m;

	char		dir;

	double		distance;
	double		corrected_distance;

	int			ceilling;
	int			floor;

	double		where;

	double		dst_to_projection;
	double		projection_3d;
	double		flo_cei;
	char		*color;

	t_data_par	*parsing;
	t_my_mlx	my_mlx;
}	t_mlx;

void	images_to_xpm(t_mlx *wind);
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
/*
	An infinite cast ray using x->cos() y->sin() until hitting the Wall
*/
void	cast_rays(t_mlx *wind, double angle, int i);
/*
	Calculating the distance based on The Pythagorean theorem
*/
double	calculate_distance(double y_player, double x_player, double y_wall, double x_wall);
/*
	Whenever a ray hits the wall set which interface he see's based on his position [y,x] and the wall intersection[y,x]
*/
char	set_directions(double w_y, double w_x, t_mlx *wind);
/*
	Fixing the buldge left and right to render flat wall as we really see them
*/
double	fix_fisheye(t_mlx *mlx, double angle);
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
char	*north_texture(t_mlx *mlx, int i);
char	*south_texture(t_mlx *mlx, int i);
char	*east_texture(t_mlx *mlx, int i);
char	*west_texture(t_mlx *mlx, int i);
int		destroy_window(t_mlx *wind);
void	my_mlx_pixel_put(t_my_mlx *data, int x, int y, int color);

#endif
