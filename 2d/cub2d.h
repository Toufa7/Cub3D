#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

# define RED 0XFF0000
# define WHITE 0XFFFFFF
# define BLACK 0X000000
# define PURPLE 0X800080
# define BLUE 0X0000FF
# define GREEN 0X00FF00



#define TRUE 1
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
typedef struct s_window
{
    void	    *mlx;
    void	    *window;

    char        **map;

    char        *xpm_wall;
    char        *xpm_clear;
    char        *xpm_player;

    char        *wall;
    char        *clear;
    char        *player;

    double      field_of_view;
    double      x_player;
    double      y_player;
}   t_mlx;


char	*get_next_line(int fd);

#endif
