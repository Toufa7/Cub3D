/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:10:32 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/10 16:22:44 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "../cub3d.h"

char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char	*str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char	*s1, char	*s2);
int		ft_atoi(const char *str);

#endif