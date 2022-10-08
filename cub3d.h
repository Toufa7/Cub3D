/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:57:39 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/03 12:07:46 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

# define BLUE 0X0000FF
# define RED 0XFF0000
# define GREEN 0X00FF00

# define TRUE 1

typedef struct s_window
{
	void	*mlx;
	void	*window;
	char	**map;


	char	*xpm_wall;
	char	*xpm_empty;
	char	*xpm_player;


	char	*wall;
	char	*empty;
	char	*player;


	
	double	field_of_view;
	double	x_player;
	double	y_player;
	int		x_end_of_ray;
	int		y_end_of_ray;
}	t_mlx;

char	*get_next_line(int fd);
char	*read_map(int fd);
void	map_filling(t_mlx *wind);
void	move_forward(t_mlx *wind);
void	get_player_position(t_mlx *wind);
void	move_backword(t_mlx *wind);
void	move_left(t_mlx *wind);
void	move_right(t_mlx *wind);
void	cast_rays(t_mlx	*wind, float nbr_ray, int i);
void	projecting_rays(t_mlx	*wind);
int		get_keys(int press, t_mlx	*wind);
int		destroy_window(t_mlx *wind);

#endif
