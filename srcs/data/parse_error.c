#include "doom_nukem.h"

void 	ft_count_brace(char **tab)
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
		{
			brace--;
		}	
		i++;
	}
	if (brace != 0)
	{	
		ft_putendl("error brace");
		exit(0);
	}
}

// void	ft_is_it_here(char **tab)
// {
// 	int i;

// 	i = 0;
// 	while (tab[i])
// 	{	
// 		if (ft_strstr(tab[i], "{"))
// 		{
// 			while (tab[i])
// 			{
				
// 				i++;
// 			}		
// 		}
// 		i++;
// 	}
// }
int 	ft_parse_error(char **tab)
{	
	// ft_is_it_here(tab);
	ft_count_brace(tab);
	return (0);
}