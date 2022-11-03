/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:11:47 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/21 14:40:02 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*dup;
	size_t	i;
	size_t	l;
	size_t	memory;

	if (!s1)
		return (0);
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
