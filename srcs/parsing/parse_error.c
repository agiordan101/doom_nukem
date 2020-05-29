/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:04:54 by aducimet          #+#    #+#             */
/*   Updated: 2020/03/12 20:42:59 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static int	ft_if_value(char **tab)
{
	int i;
	int y;
	int count;

	i = -1;
	count = 0;
	while (tab[++i])
	{
		if (ft_strstr(tab[i], "="))
		{
			y = -1;
			while (tab[i][++y])
			{
				count = 0;
				if ((tab[i][y] >= 48 && tab[i][y] <= 122) ||
				tab[i][y] == 40 || tab[i][y] == 41)
					count++;
			}
			if (count == 0)
				return (-1);
		}
	}
	return (0);
}

static int	ft_count_brace(char **tab)
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
		return (-1);
	return (0);
}

int			ft_parse_error(char **tab)
{
	if ((ft_if_value(tab) == -1) || (ft_count_brace(tab) == -1))
		return (-1);
	return (0);
}
