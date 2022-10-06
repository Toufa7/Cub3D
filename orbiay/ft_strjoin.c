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
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	//if (s1 == 0 || s2 == 0)
	//	return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			join[j++] = s1[i++];
		}
	}
	i = 0;
	if (s2)
	{
		while (s2[i] != '\0')
		{
			join[j++] = s2[i++];
		}
	}
	join[j] = '\0';
	free(s1);
	return (join);
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