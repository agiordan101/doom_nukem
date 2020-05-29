/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrpushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:20:19 by gal               #+#    #+#             */
/*   Updated: 2020/05/29 13:45:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		copytab2d(char **tab, char **ntab, int len, int i)
{
	int j;

	j = 0;
	while (j < len)
	{
		ntab[i][j] = tab[i][j];
		j++;
	}
	ntab[i][j] = '\0';
}

void		copytab(char **ntab, char *line, int len, int i)
{
	int j;

	j = 0;
	while (j < len)
	{
		ntab[i][j] = line[j];
		j++;
	}
	ntab[i++][j] = '\0';
	ntab[i] = NULL;
}

char		**ft_2dstrpushback(char **tab, int size_i, char *line)
{
	char	**ntab;
	int		i;
	int		len;

	if (!(ntab = (char**)ft_memalloc(sizeof(char*) * (size_i + 2))))
		return (NULL);
	i = 0;
	while (i < size_i)
	{
		len = ft_strlen(tab[i]);
		if (!(ntab[i] = (char*)ft_memalloc(sizeof(char) * (len + 1))))
			return (NULL);
		copytab2d(tab, ntab, len, i);
		i++;
	}
	len = ft_strlen(line);
	if (!(ntab[i] = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	copytab(ntab, line, len, i);
	return (ntab);
}
