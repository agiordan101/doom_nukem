#include "../includes/libft.h"

int     ft_2dstrlen(char **tab)
{
    int     len;

    len = 0;
    if (tab)
    {
        while (tab[len])
            len++;
    }
    return (len);
}