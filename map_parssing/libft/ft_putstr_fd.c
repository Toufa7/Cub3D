/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:23:19 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/14 17:52:56 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includ/map_parssing.h"
void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (!s || !fd)
		return ;
	while (s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}
