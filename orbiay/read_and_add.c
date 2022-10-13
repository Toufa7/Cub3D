/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:50:21 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/12 16:30:57 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*only_map(char *str)
{
	char	**sp_str;
	char	*ret_str;
	int		i;
	int		count;

	i = 6;
	ret_str = NULL;
	sp_str = NULL;
	sp_str = ft_split(str, '\n');
	count = counting(sp_str);
	while (i < count)
	{
		if (i > 6)
			ret_str = ft_strjoin(ret_str, "\n");
		ret_str = ft_strjoin(ret_str, sp_str[i]);
		i++;
	}
	return (ret_str);
}

t_fd	read_and_add(char **av)
{
	int		fd;
	char	*str;
	char	*buf;
	t_fd	fd2;	

	fd = open(av[1], O_RDONLY);
	fd2.full_map = NULL;
	if (fd == -1)
	{
		perror("Error\n");
		exit (0);
	}
	str = NULL;
	buf = get_next_line(fd);
	while (buf)
	{
		str = ft_strjoin(str, buf);
		if (!strcmp(str, "\n"))
		{
			printf("Error : There is a new line in map");
			exit(1);
		}
		free(buf);
		buf = get_next_line(fd);
	}
	free(buf);
	if (!str)
	{
		printf("Error : Map invalid");
		exit(1);
	}
	if (map_checking(str))
	{
		fd2 = take_path(str);
		if (!map_checking2(str) || !check_colors_valid(fd2.F, fd2.C))
			exit(0);
		printf("\nALL thing is valid\n");
	}
	return (fd2);
}
