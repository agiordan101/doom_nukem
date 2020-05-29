/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dintpushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:44:16 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/17 23:10:49 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	fill_j_line(int **ntab, int **tab,
						int size_j, const int i)
{
	int	j;

	j = 0;
	if (!(ntab[i] = (int*)ft_memalloc(sizeof(int) * size_j)))
		return (0);
	while (j < size_j)
	{
		ntab[i][j] = tab[i][j];
		j++;
	}
	return (1);
}

int			**ft_2dintpushback(int **tab, int size_i, int size_j, int *line)
{
	int	**ntab;
	int	i;
	int j;

	if (!(ntab = (int**)ft_memalloc(sizeof(int*) * (size_i + 1))))
		return (NULL);
	i = 0;
	while (i < size_i)
	{
		if (!fill_j_line(ntab, tab, size_j, i))
			return (NULL);
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
