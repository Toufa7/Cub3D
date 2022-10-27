/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:29:31 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/16 07:31:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/map_parssing.h"
#include<stdio.h>
/* change one thing in this function the position of indext to start  */

static char	*ft_strcat_p(char *dest, const char *src, int position)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[i] != '\0' && position != 0)
		i++;
	while (src[len] != '\0')
	{
		dest[i] = src[len];
		i++;
		len++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		index;
	int		length;
	char	*ptr;

	index = 0;
	if (!s1 || !s2)
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(length);
	if (ptr == NULL)
		return (0);
	ft_strcat_p(ptr, s1, 0);
	ft_strcat_p(ptr, s2, 1);
	return (ptr);
}
/*
int main()
{
  printf("%s",ft_strjoin("","alami"));
}
*/
