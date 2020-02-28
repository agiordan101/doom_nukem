#include "../includes/libft.h"

void    ft_2dputendl(const char **str)
{
    int     i;

    i = 0;
    while (str[i])
        ft_putendl(str[i++]);
}