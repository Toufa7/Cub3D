/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:38:51 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/20 11:15:54 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	req_zero(char **str, int start, int i)
{
	int	count;

	count = 0;
	if (!str[start + 1])
		count++;
	if (str[start][i + 1] && str[start][i + 1] != '0'
		&& !check_player(str[start][i + 1]) && str[start][i + 1] != '1')
	{
		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
		return (0);
	}
	if (str[start][i - 1] && str[start][i - 1] != '0'
		&& str[start][i - 1] != '1' && !check_player(str[start][i - 1]))
	{
		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
		return (0);
	}
	if ((!str[start + 1][i]) || (str[start + 1][i] && str[start + 1][i] != '0'
		&& !check_player(str[start + 1][i]) && str[start + 1][i] != '1'))
	{
		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
		return (0);
	}
	if ((!str[start - 1][i]) || (str[start - 1][i] && str[start - 1][i] != '0'
		&& !check_player(str[start - 1][i]) && str[start - 1][i] != '1'))
	{
		printf("Error Map : U have Problem in Row[%d][%d].", start, i);
		return (0);
	}
	return (1);
}

int	check_spaces(char **str, int start)
{
	int		j;
	int		count;

	count = counting(str);
	j = 0;
	while (str[start])
	{
		j = 0;
		if (!check_walls(str[start], start, count))
			return (0);
		while (str[start][j])
		{
			if (str[start][j] == '0' && !req_zero(str, start, j))
				return (0);
			j++;
		}
		start++;
	}
	return (1);
}

int	check_player(char str)
{
	if (str == 'N' || str == 'S' || str == 'E' || str == 'W')
		return (1);
	return (0);
}

int	last_touches(char	**str)
{
	int		count_0;
	int		cout_p;
	int		i;
	int		j;

	j = 0;
	i = 6;
	cout_p = 0;
	count_0 = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (check_player(str[i][j]))
				cout_p++;
			j++;
		}
		i++;
	}
	if ( (cout_p == 0 || cout_p > 1) || i == 6)
	{
		printf("Error : There is a problem");
		return (0);
	}
	return (1);
}

int	check_colors_valid(char *F, char *C)
{
	char	**sp_f;
	char	**sp_c;

	sp_c = ft_split(ft_strdup(C), ',');
	sp_f = ft_split(ft_strdup(F), ',');
	if (counting(sp_f) != 3 || counting(sp_c) != 3)
	{
		printf("Error : There is problem in COLORS.");
		ft_free(sp_f);
		ft_free(sp_c);
		return (0);
	}	
	if (!check_isdigit(sp_f) || !check_isdigit(sp_c))
	{
		ft_free(sp_f);
		ft_free(sp_c);
		return (0);
	}
	if (!check_comma(F) || !check_comma(C))
	{
		ft_free(sp_f);
		ft_free(sp_c);
		return (0);
	}
	ft_free(sp_f);
	ft_free(sp_c);
	return (1);
}
