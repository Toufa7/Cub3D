/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:58:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/25 11:08:16 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parssing.h"


static int	min_mal(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	unsigned int	len_sub_str;
	char			*ptr;

	index = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		ptr = malloc(1);
		ptr[0] = 0;
		return (ptr);
	}
	len_sub_str = min_mal(ft_strlen(s) - start, len);
	ptr = malloc(len_sub_str + 1);
	if (ptr == NULL)
		return (0);
	while (index < len_sub_str && s[index] != '\0')
	{
		ptr[index] = s[index + start];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}

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

char	*ft_strjjoin(char *s1, char *s2)
{
	int		index;
	int		length;
	char	*ptr;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	index = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(length + 1);
	if (ptr == NULL)
		return (0);
	ft_strcat_p(ptr, s1, 0);
	ft_strcat_p(ptr, s2, 1);
	free(s1);
	return (ptr);
}
