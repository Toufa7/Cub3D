/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   To_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:38:37 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/08 16:59:24 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int check_newline(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '\n' && str[i + 1] && str[i + 1] == '\n')
        {
              printf("str = %c\n",str[i]);
            return 0;
        }
        i++;
    }
    return 1;
}