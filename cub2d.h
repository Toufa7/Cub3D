#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

#define BLUE 0X0000FF
#define RED 0XFF0000
#define TRUE 1

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
