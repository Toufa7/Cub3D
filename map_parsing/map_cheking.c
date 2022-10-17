/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:47:49 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/13 18:44:25 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	map_checking2(char	*str)
{
	char	**split_str;
	int		statrt;

	statrt = 6;
	split_str = ft_split(str, '\n');
	if (!check_spaces(split_str, statrt))
		return (0);
	if (!last_touches(split_str))
		return (0);
	return (1);
}

// t_fd init_fd(t_fd fd)
// {
// 	fd.C = NULL;
// 	fd.EA = NULL;
// 	fd.F = NULL;
// 	fd.full_map = NULL;
// 	fd.NO = NULL;
// 	fd.SO = NULL;
// 	fd.WE = NULL;
// 	return (fd);
// }

t_fd	file_dis(char *sp, char *s)
{
	t_fd	fd;

	fd.full_map = NULL;
	if (!strcmp(sp, "NO"))
		fd.NO = ft_strdup(s);
	else if (!strcmp(sp, "SO"))
		fd.SO = ft_strdup(s);
	else if (!strcmp(sp, "WE"))
		fd.WE = ft_strdup(s);
	else if (!strcmp(sp, "EA"))
		fd.EA = ft_strdup(s);
	else if (!strcmp(sp, "F"))
		fd.F = ft_strdup(s);
	else if (!strcmp(sp, "C"))
		fd.C = ft_strdup(s);
	return (fd);
}

t_fd	take_path(char	*str)
{
	char	**str_sp;
	char	**sp;
	char	*s;
	t_fd	fd;
	int		i;

	i = 0;
	str_sp = ft_split(ft_strdup(str), '\n');
	while (i < 6)
	{
		sp = ft_split(ft_strdup(str_sp[i]), ' ');
		s = joining(sp);
		fd = file_dis(sp[0], s);
		ft_free(sp);
		free(s);
		i++;
	}
	fd.full_map = only_map(ft_strdup(str));
	return (fd);
}

int	check_isdigit(char **sp)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	while (sp[i])
	{
		j = 0;
		num = ft_atoi(sp[i]);
		if (num > 255 || num < 0)
		{
			printf("Error :Colors  %s High Than 255\n", sp[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_extension(char *av[])
{
	if (strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
	{
		printf("Provide a .cub file\n");
		exit(1);
	}
}
