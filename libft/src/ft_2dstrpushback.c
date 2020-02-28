#include "../includes/libft.h"
#include <stdio.h>

char		**ft_2dstrpushback(char **tab, int size_i, char *line)
{
	char    **ntab;
	int	    i;
	int     j;
    int     len;

	if (!(ntab = (char**)ft_memalloc(sizeof(char*) * (size_i + 2))))
		return (NULL);
	i = 0;
	while (i < size_i)
	{
        len = ft_strlen(tab[i]);
		if (!(ntab[i] = (char*)ft_memalloc(sizeof(char) * (len + 1))))
			return (NULL);
		j = 0;
		while (j < len)
		{
			ntab[i][j] = tab[i][j];
			j++;
		}
		ntab[i][j] = '\0';
		i++;
	}
    len = ft_strlen(line);
	if (!(ntab[i] = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	j = 0;
	while (j < len)
	{
		ntab[i][j] = line[j];
		j++;
	}
	ntab[i++][j] = '\0';
	ntab[i] = NULL;
	return (ntab);
}