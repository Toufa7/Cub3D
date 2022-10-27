/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 08:18:07 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/17 10:12:01 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include "../includ/map_parssing.h"
#include<unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
// https://www.cse.cuhk.edu.hk/~ericlo/teaching/os/lab/11-FS/fd.html
int main()
{

 int fd = open("test_f_r.txt", O_RDWR);
 char c; 
 int bytes;
   printf(" %d ",fd);

    ft_putchar_fd('d',fd);

 close(fd);  
}
*/
