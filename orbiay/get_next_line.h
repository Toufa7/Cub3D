/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:45:50 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/06 15:13:54 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strrlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_find_len(char *str, char what);
char	*ft_strchar(char *str, char what);
char	*ft_strjjoin(char *str1, char *str2);
char	*ft_subsstr(char *str, size_t start, size_t how);
char	*cutting_until_newline(char *str);
char	*keeping_what_after_newline(char *str);
char	*read_and_join(int fd, char *save);
char	*get_next_line(int fd);
int ft_strlen (char *str);
char	**ft_split(char const *s, char c);
int strcmp(const char *s1, const char *s2);
int check_NO(char **str);
int check_C(char **str);
int check_F(char **str);
int check_EA(char **str);
int check_WE(char **str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int check_SO(char **str);
int counting(char **str);
char *joining(char **str);
int check_Walls(char *str,int start,int count);
int	ft_atoi(const char *str);

typedef struct  fd
{
    char* NO;
    char* SO;
    char* WE;
    char* EA;
    char*  F;
    char*  C;
    char* full_map;
}t_fd;


#endif
