/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:03:50 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/12 16:28:17 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
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
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"


# define BLUE 0Xc0dfef
# define RED 0XFF0000
# define GREEN 0X74d434

//!*-*-*-*-*-*-*-*-*-*-*-*-*-*Orbiay Part*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*

typedef struct fd
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	*full_map;
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

//*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-Otoufah Part*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef	struct s_my_mlx
{
	void	*img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}	t_my_mlx;

typedef struct s_window
{

	void	*mlx;
	void	*window;
	char	**map;
	double	field_of_view;
	double	x_player;
	double	y_player;
	double	x_end_of_ray;
	double	y_end_of_ray;

	t_fd	parsing;
	t_my_mlx my_mlx;

}	t_mlx;

char	*get_next_line(int fd);
char	*read_map(int fd);
void	map_filling(t_mlx *wind);
void	move_forward(t_mlx *wind);
void	get_player_position(t_mlx *wind);
void	move_backword(t_mlx *wind);
void	move_left(t_mlx *wind);
void	move_right(t_mlx *wind);
void	cast_rays(t_mlx *wind, double nbr_ray , int i);
void	projecting_rays(t_mlx *wind);
void	casting_3d(double distance, int i, t_mlx *mlx);
int		get_keys(int press, t_mlx	*wind);
int		destroy_window(t_mlx *wind);
void	my_mlx_pixel_put(t_my_mlx *data, int x, int y, int color);

#endif
