/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:32:00 by otoufah           #+#    #+#             */
/*   Updated: 2021/11/27 00:04:04 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	char	*str;
	int		i;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	str = malloc((ft_strlen(s1) + ft_strlen(s2) +1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	lens1 = 0;
	while (s2[lens1])
	{
		str[i] = ((char *)s2)[lens1];
		i++;
		lens1++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

int ft_strlen (char *str)
{
	int i = 0;
	if (!str)
		return 0;
	while (str[i])
	{
		i++;
	}
	return i;
}