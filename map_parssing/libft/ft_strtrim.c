/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:32:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/25 14:40:55 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/map_parssing.h"
#include<stdio.h>
static int	chec_in_set(char *ptr, char c)
{
	int	index;

	index = 0;
	while (ptr[index] != '\0')
	{
		if (c == ptr[index])
			return (1);
		index++;
	}
	return (0);
}

static char	*ft_strdup_n(char *src, int n)
{
	char	*ptr;
	int		i;

	i = 0;
	if (n < 0)
		n = 0;
	ptr = malloc((n + 1) * sizeof (char));
	if (ptr == 0)
		return (0);
	while (i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*remove_from_beg_end(char *s1, char *set, char *ptr, int s_length)
{
	int	stop;
	int	stop1;
	int	index;
	int	l;

	stop = 1;
	stop1 = 1;
	index = 0;
	l = 0;
	while (s1[index] != '\0')
	{
		if (stop && chec_in_set(set, s1[index]))
			ptr++;
		else
			stop = 0;
		if (stop1 && chec_in_set(set, (char)s1[--s_length]))
			l++;
		else
			stop1 = 0;
		index++;
	}
	ptr = ft_strdup_n(ptr, ft_strlen(ptr)-l);
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s_length;
	char	*ptr;

	if (!s1)
		return (0);
	ptr = (char *)s1;
	s_length = ft_strlen((char *)s1);
	
	ptr = remove_from_beg_end((char *)s1, (char *)set, ptr, s_length);
	// printf(" %p \n",s1);
	return (ptr);
}

// int main()
// {
	
//     const char set[] = " \n\t";
//     char *s1 = "  \t \t \n   \n\n\n\t";
// 	char *s2 = "";
// 	char *ret = ft_strtrim("     NO ./texture/the_north_texture.xpm", " ");

//    // char *a = ft_strtrim(tab,set);
//    printf(" %s ", ret);    
// }

