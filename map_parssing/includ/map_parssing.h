/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parssing.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:30:19 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/24 12:31:38 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSSING_H
#define MAP_PARSSING_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/wait.h>

//# include "../so_long/so_long.h"
# define HIX "0123456789abcdef"

/*  this struct have some membres releted of data in the map */
typedef struct s_data_par {
	char    *north_path;
    char    *south_path;
    char    *west_path;
    char    *east_path;
    
    int     ciling_color;
    int     floor_color;
    double  tita;
    char    **maze;
    int     nbr_lin;
    int     x_player;
    int     y_player;
}				t_data_par;

/* this struct have some index membres for check numbers of this elements in the file */
typedef struct s_index {
	int n_derc;
	int n_color;
	int maze_index;
	int new_line;
}   t_index;


/*  check and get data form file.cub*/
void ft_parsing(int argc, char **argv, t_data_par *parsing);

/* read map and ansert data to t_data_par  */
void	read_map(char *file, t_data_par *parsing);

/* check the file is exist or not */
int		check_file_argument(char **argv, int argc);

/* get nbr of lines in the fd (cub utils) */
int get_nbr_line(int fd);

/* print the data parssing */
void print_data(t_data_par *parsing);

/* check the coloe and convet it to int varialble*/
void	get_color_values(t_data_par *parsing , char *line, t_index *index);

char	*ft_itoa(int n);
void	ft_free(char **leaks);
void	print_tab(char **tab);

//!-----------Errors-----------------
void error_line();
void error_map();
void error_player();
void error_color();
/*!-----------Texture-----------------*/
void texture_value(t_data_par *parsing, char *line, int *nbr);
void check_textures(t_data_par *parsing ,t_index *index , char *line);
char *get_path_check(char *line, char *ser);
//void check_texture(t_data_par *parsing,int n_derc , int n_color);
//!------------tools--------------------
/* check_possiblt of texture  */
int check_possiblty_tex(char *line);
int check_possiblty(char c);
void init(t_data_par *parsing);

/* check line if any zero in it */
int true_line(char *str);
void free_function(char **str);



//!-----------------get_next--------
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
int		check_fun(char *s);
// int		check_back_s(char *s);
char	*d_line(char *line);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//!------------lib---------------
int		ft_atoi(const char *nbr);
void	*ft_calloc(size_t len, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjjoin(char *s1, char *s2);
void    check_maze_player(t_data_par *parsing);
void around_ps(char **maze, int i, int index);
int around_zero(t_data_par *parsing, int index, char *line , int i);
#endif