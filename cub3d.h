#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

#define BLUE 0X0000FF
#define RED 0XFF0000
#define TRUE 1

typedef struct s_window
{
    void	    *mlx;
    void	    *window;

    char        **map;

    char        *wall_1;
    char        *empty_1;
    char        *player_1;

    char        *wall;
    char        *empty;
    char        *player;

    double      field_of_view;
    double      xstep;
    double      ystep;
}   t_window;


char	*get_next_line(int fd);

#endif
