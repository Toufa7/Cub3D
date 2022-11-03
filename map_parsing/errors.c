/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:33:05 by ael-oual          #+#    #+#             */
/*   Updated: 2022/10/28 18:51:05 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includ/map_parsing.h"

void	error_line(t_data_par *parsing)
{
	free(parsing);
	printf(" error line \n");
	exit(1);
}

void	error_map(t_data_par *parsing)
{
	free(parsing);
	printf(" error map \n");
	exit(1);
}

void	error_color(t_data_par *parsing)
{
	free(parsing);
	printf(" error color \n");
	exit(1);
}
