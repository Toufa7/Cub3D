/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:47:55 by otoufah           #+#    #+#             */
/*   Updated: 2022/10/09 14:46:49 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*cutting_until_newline(char *str)
{
	if (!str)
		return (NULL);
	return (ft_subsstr(str, 0, ft_find_len(str, '\n')));
}

char	*keeping_what_after_newline(char *str)
{
	size_t	idx;
	char	*remain;

	if (!str)
		return (NULL);
	idx = ft_find_len(str, '\n');
	remain = ft_subsstr(str, idx, ft_strlen(str) - idx);
	free(str);
	return (remain);
}

char	*read_and_join(int fildes, char *save)
{
	char	*buf;
	int		nbytes;

	buf = malloc(sizeof(char) * 1 + 1);
	if (!buf)
		return (NULL);
	nbytes = 1;
	while (!ft_strchar(save, '\n') && nbytes != 0)
	{
		nbytes = read(fildes, buf, 1);
		if (nbytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nbytes] = '\0';
		save = ft_strjjoin(save, buf);
	}
	free(buf);
	if (!save[0] && nbytes == 0)
	{
		free(save);
		return (NULL);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;

	if (fd < 0 || 1 <= 0)
		return (NULL);
	saved = read_and_join(fd, saved);
	if (!saved)
		return (NULL);
	line = cutting_until_newline(saved);
	saved = keeping_what_after_newline(saved);
	return (line);
}
