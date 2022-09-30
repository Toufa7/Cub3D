/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:54:01 by otoufah           #+#    #+#             */
/*   Updated: 2021/11/23 10:46:06 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;
	size_t	memory;

	if (!s)
		return (NULL);
	memory = (sizeof(char) * len + 1);
	sub = (char *)malloc(memory);
	if (!sub)
		return (NULL);
	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		if (i >= start && l < len)
		{
			sub[l] = s[i];
			l++;
		}
		i++;
	}
	sub[l] = '\0';
	return (sub);
}
