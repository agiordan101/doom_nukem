#include "doom_nukem.h"

void	ft_if_value(char **tab)
{
	int i;
	int y;
	int count;

	y = 0;
	i = 0;
	count = 0;
	while (tab[i])
	{
		if (ft_strstr(tab[i], "="))
		{
			y = 0;
			while (tab[i][y])
			{
				count = 0;
				if ((tab[i][y] >= 48 && tab[i][y] <= 122) ||
				tab[i][y] == 40 || tab[i][y] == 41)
					count++;
				y++;
			}
			if (count == 0)
			{
				printf("i = %d\n", i);
				ft_putendl("error value");
				exit(0);             // a modifier
			}
		}
		i++;
	}
}

static void	ft_count_brace(char **tab)
{
	int i;
	int brace;

	i = 0;
	brace = 0;
	while (tab[i])
	{
		if (ft_strchr(tab[i], '{') == NULL)
			brace++;
		if (ft_strchr(tab[i], '}') == NULL)
			brace--;
		i++;
	}
	if (brace != 0)
		ft_putendl("error brace");
}
// static void needed_value(char **tab)
// {
// 	int i;

// 	i = 0;
// 	while(tab[i])
// 	{
// 		if (ft_strstr(tab[i], "mob"))
// 		{
			
// 		}
// 		i++;
// 	}

// }

int		ft_parse_error(char **tab)
{
	ft_if_value(tab);
	ft_count_brace(tab);
	return (0);
}
