/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:28:24 by orbiay            #+#    #+#             */
/*   Updated: 2022/10/03 19:02:21 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int counting(char **str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
int len(char **str)
{
    int i = 1;
    int  j = 0;
    int sum = 0;
    while (str[i])
    {
         j = 0;
        while (str[i][j])
            j++;
        sum += j;
        i++;
    }
    return sum;
}
char *joining(char **str)
{
    int i = 1;
    int j = 0;
    int k = 0;
    int count  = counting(str) - 1 ; // -1 7itach bghit nabda men la arg tani lihowa 1
    char *re_str = malloc(len(str) + 1 + count);
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            re_str[k] = str[i][j];
            j++;
            k++;
        }
        if (count - 1 != 0)
        {
            re_str[k++] = ' ';
            count--;
        }
        i++;
    }
    re_str[k] = '\0';
    return re_str;
}
int check_NO(char **str)
{
    if (!strcmp(str[0],"NO") && counting(str) >= 2)
        return 1;
    return 0;
}

int check_SO(char **str)
{
    if (!strcmp(str[0],"SO") && counting(str) >= 2)
        return 1;
    return 0;
}

int check_WE(char **str)
{
    if (!strcmp(str[0],"WE")&& counting(str) >= 2)
        return 1;
    return 0;
}

int check_EA(char **str)
{
    if (!strcmp(str[0],"EA") && counting(str) >= 2)
        return 1;
    return 0;
}

int check_F(char **str)
{
    if (!strcmp(str[0],"F") && counting(str) == 2)
        return 1;
    return 0;
}

int check_C(char **str)
{
    
    if (!strcmp(str[0],"C") && counting(str) == 2)
        return 1;
    return 0;
}
