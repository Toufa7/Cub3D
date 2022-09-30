#include "libft.h"

void    ft_free(char *str)
{
	if (str)
		free(str);
}

void    ft_free_double(char **str)
{
	int i;

	i = -1;
	while (str && str[++i])
		ft_free(str[i]);
	if (str)
		free(str);
}