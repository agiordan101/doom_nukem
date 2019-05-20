/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_2dintpushback.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 11:44:16 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:15:00 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		**ft_2dintpushback(int **tab, int size_i, int size_j, int *line)
{
	int	**ntab;
	int	i;
	int j;

	if (!(ntab = (int**)ft_memalloc(sizeof(int*) * (size_i + 1))))
		return (NULL);
	i = 0;
	while (i < size_i)
	{
		j = 0;
		if (!(ntab[i] = (int*)ft_memalloc(sizeof(int) * size_j)))
			return (NULL);
		while (j < size_j)
		{
			ntab[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	if (!(ntab[i] = (int*)ft_memalloc(sizeof(int) * size_j)))
		return (NULL);
	j = 0;
	while (j < size_j)
	{
		ntab[i][j] = line[j];
		j++;
	}
	return (ntab);
}
