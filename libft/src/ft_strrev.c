#include "../includes/libft.h"

char    *ft_strrev(char *str)
{
    char    *str_rev;
    int     i;
    int     i_rev;

    if (str)
    {
        if (!(str_rev = (char*)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1))))
            return (NULL);
        i = ft_strlen(str) - 1;
        i_rev = 0;
        while (i >= 0)
            str_rev[i_rev++] = str[i--];
        return (str_rev);
    }
    return (NULL);
}