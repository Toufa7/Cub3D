/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:57:39 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/09 14:53:51 by orbiay           ###   ########.fr       */
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
// # include "./libft/libft.h"
// # include "./orbiay/parsing_map.h"

# define BLUE 0X0000FF
# define RED 0XFF0000
# define GREEN 0X00FF00

# define TRUE 1

typedef struct  fd
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *F;
    char    *C;
    char    *full_map;
}   t_fd;



typedef struct s_window
{
	t_fd	parsing;

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


//!---------------------------Orbiay Part --------------------------!//


int		check_newline(char *str);
int		check_NO(char **str);
int		check_C(char **str);
int		check_F(char **str);
int		check_EA(char **str);
int		check_WE(char **str);
int		check_SO(char **str);
int		counting(char **str);
char	*joining(char **str);
int		check_Walls(char *str,int start,int count);
int     check_newline(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_find_len(char *str, char what);
char	*ft_strchar(char *str, char what);
char	*ft_subsstr(char *str, size_t start, size_t how);
char	*cutting_until_newline(char *str);
char	*keeping_what_after_newline(char *str);
char	*read_and_join(int fd, char *save);
int		ft_atoi(const char *str);
int     ft_strlen (char *str);
char	**ft_split(char const *s, char c);
t_fd	read_and_add(char **av);



//!---------------------------Otoufah Part --------------------------!//
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
