/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:57:49 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/22 12:08:41 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <string.h>

int	check_f_c(char	**str,	int line)
{
	static int	f;
	static int	c;

	if (check_f(str))
		f++;
	else if (check_c(str))
		c++;
	else if (f > 1 || c > 1)
	{
		printf("Error Map : Duplicate.");
		return (0);
	}
	if (line == 5 && (c == 0 || f == 0))
	{
		printf("Error : Problem in Color .");
		return (0);
	}
	return (1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_textures(char **str,	int line)
{
	static int	no;
	static int	so;
	static int	we;
	static int	ea;

	if (str[0] && strcmp(str[0], "NO") && strcmp(str[0], "SO")
		&& strcmp(str[0], "WE") && strcmp(str[0], "EA")
		&& strcmp(str[0], "F") && strcmp(str[0], "C"))
	{
		printf("Error : Textures or Colors undefined.");
		return (0);
	}
	if (check_no(str))
		no++;
	else if (check_so(str))
		so++;
	else if (check_we(str))
		we++;
	else if (check_ea(str))
		ea++;
	else if (no > 1 || so > 1 || we > 1 || ea > 1)
	{
		printf("Error Map : Duplicate.");
		return (0);
	}
	else if (line == 5 && (no == 0 || so == 0 || we == 0 || ea == 0))
	{
		printf("Error Map : Something Wrong whith Textures.");
		return (0);
	}
	return (check_f_c(str, line));
}

int	first_six_lines(char *split_str,	int line)
{
	char	*str;
	char	**split;

	str = ft_strdup(split_str);
	split = ft_split(str, ' ');
	if (!check_textures(split, line))
	{
		ft_free(split);
		free(str);
		return (0);
	}
	ft_free(split);
	free(str);
	return (1);
}

int	map_checking(char *str)
{
	char	**split_str;
	int		i;

	i = 0;
	split_str = ft_split(str, '\n');
	while (i < 6)
	{
		if (!first_six_lines(split_str[i], i))
		{
			ft_free(split_str);
			return (0);
		}
		i++;
	}
	ft_free(split_str);
	return (1);
}

//int	req_space(char **str, int start, int i)
//{
//	int	count;
//	int	len;
//
//	len = ft_strlen(str[start + 1]);
//	count = 0;
//	if (!str[start + 1])
//		count++;
//	if (str[start][i + 1] && str[start][i + 1] != ' '
//		&& str[start][i + 1] != '1')
//	{
//		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
//		return (0);
//	}
//	if (i > 0 && str[start][i - 1] != ' ' && str[start][i - 1] != '1')
//	{
//		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
//		return (0);
//	}
//	//if(!count && str[start + 1][i] && str[start + 1][i] != ' ' && str[start + 1][i] != '1')
//	//{
//	//    printf("Error Map : U have Problem in Row[%d][%d].",start,i);
//	//    return 0;
//	//}
//	//printf("len=  %d && i = %d\n",len,i);
//	if (i < len - 1 && str[start + 1] && str[start + 1][i] && str[start + 1][i] != ' ' && str[start + 1][i] != '1')
//	{
//	    printf("c=  %c\n",str[start + 1][i]);
//	    printf("3Error Map : U have Problem in Row[%d][%d].",start,i);
//	    return 0;
//	}
//	printf("4\n");
//	printf("starrrt =  %d\n",start);
//	if(start > 6 && str[start - 1] && str[start - 1][i] && str[start - 1][i] != ' ' && str[start - 1][i] != '1' )
//	{
//	    printf("Error Map : U have Problem in Row[%d][%d].",start,i);
//	    return 0;
//	}
//	printf("5\n");
//	return 1;
//}
// int main (int ac , char **av)//map with '\n'
// {
//     t_fd fd2;
//     fd2 = read_and_add(av);
//     return (0);
// }