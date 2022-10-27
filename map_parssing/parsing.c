/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:33:53 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/27 18:00:56 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parssing.h"
// int ft_direc(char c)
// {
// 	if (c == 'S')
// 		return 90;
// 	else if(c == 'N')
// 		return 270;
// 	else if(c == 'W')
// 		return 180;
// 	return 360;
// }

void	erros_functions(char **argv)
{
	int	length;

	length = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".cub", argv[1] + length, 5) != 0)
	{
		ft_putstr_fd(" Error ./cub", 2);
		exit(1);
	}
}

int	check_file_argument(char **argv, int argc)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(0);
	}
	erros_functions(argv);
	if (argc != 2)
	{
		ft_putstr_fd(" <error arrgument> \n", 2);
		exit(1);
	}
	return (fd);
}

int	get_nbr_line(int fd)
{
	char	*line;
	int		nbr_lin;

	nbr_lin = 0;
	line = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
		{
			close(fd);
			break ;
		}
		free(line);
		nbr_lin++;
	}
	if (nbr_lin == 0)
		error_map();
	return (nbr_lin);
}

void	ft_parsing(int argc, char **argv, t_data_par *parsing)
{
	int	nbr_lin;
	int	length_line;

	nbr_lin = 0;
	length_line = 0;
	init(parsing);
	nbr_lin = get_nbr_line(check_file_argument(argv, argc));
	parsing->maze = malloc(nbr_lin * sizeof(char *));
	parsing->nbr_lin = nbr_lin;
	read_map(argv[1], parsing);
}
