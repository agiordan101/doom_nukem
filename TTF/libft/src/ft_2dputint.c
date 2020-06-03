/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dputint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:35:00 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/29 13:44:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_2dputint(int **tab, int ilen, int jlen)
{
	int		i;
	int		j;

	if (tab)
	{
		i = 0;
		while (i < ilen)
		{
			j = 0;
			while (j < jlen)
			{
				ft_putnbr(tab[i][j++]);
				ft_putchar(' ');
			}
			ft_putchar('\n');
			i++;
		}
	}
}
