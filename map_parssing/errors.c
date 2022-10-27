/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:33:05 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/27 22:54:45 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parssing.h"

	// system("leaks cub3d");
void	error_line(void)
{
	printf(" error line [<>!<>] \n");
	exit(1);
}

void	error_map(void)
{
	printf(" error map [<>!<>] \n");
	exit(1);
}

void	error_player(void)
{
	printf(" error player [<>!<>] \n");
	exit(1);
}

void	error_color(void)
{
	printf(" error color [<>!<>] \n");
	exit(1);
}