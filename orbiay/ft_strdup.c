/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:14:42 by otoufah           #+#    #+#             */
/*   Updated: 2021/11/23 14:31:13 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*dup;
	size_t	i;
	size_t	l;
	size_t	memory;
	if (!s1)
		return 0;
	l = ft_strlen(s1);
	memory = (sizeof(char) * l + 1);
	dup = (char *)malloc(memory);
	if (!(dup && s1))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	rest;
	int	sen;

	i = 0;
	rest = 0;
	sen = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sen = sen * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		rest = rest * 10 + str[i] - 48;
		i++;
	}
	return (rest * sen);
}
