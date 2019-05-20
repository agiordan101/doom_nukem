#include "../includes/libft.h"

int	ft_count_char(char *str, int c)
{
	int	i;
	int	nb_char;

	i = 0;
	nb_char = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb_char++;
		i++;
	}
	return (nb_char);
}