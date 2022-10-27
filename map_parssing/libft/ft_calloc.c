/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:16:54 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/15 10:28:12 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includ/map_parssing.h"

void	*ft_calloc(size_t len, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	sum;

	i = 0;
	sum = len * size;
	ptr = malloc((len * size));
	if (ptr == NULL)
		return (0);
	while (sum)
	{
		ptr[i] = 0;
		sum--;
		i++;
	}
	return (ptr);
}
/*
int main()
{
	int *ptr = ft_calloc(5,4);
    printf(" %d ",ptr[5]);

}
*/
