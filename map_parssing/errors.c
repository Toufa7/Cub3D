/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:33:05 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/27 18:10:34 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parssing.h"

void	error_line(void)
{
	// system("leaks cub3d");
	printf(" error line [<>!<>] \n");
	exit(1);
}

void	error_map(void)
{
	// system("leaks cub3d");
	printf(" error map [<>!<>] \n");
	exit(1);
}

void	error_player(void)
{
	// system("leaks cub3d");
	printf(" error player [<>!<>] \n");
	exit(1);
}

void	error_color(void)
{
	// system("leaks cub3d");
	printf(" error color [<>!<>] \n");
	exit(1);
}